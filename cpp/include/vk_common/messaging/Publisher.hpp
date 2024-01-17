#ifndef VKC_PUBLISHER_HPP
#define VKC_PUBLISHER_HPP

#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>

namespace vkc {
    /// Represents a publisher to a message type.
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(
            SharedBroadcastQueue<T>& queue,
            SharedCallbackPool<T>& poolPre,
            SharedCallbackPool<T>& poolPost
        ): mQueue(queue), mPoolPre(poolPre), mPoolPost(poolPost) {}
        Publisher(const Publisher&) = delete;
        Publisher(Publisher&&) = default;
        Publisher& operator=(Publisher&&) = default;

        /// Sends the given value to all subscribers.
        ///
        /// A `Message` is automatically created and wraps the given value, and other metadata
        /// (such as the publish time etc.) are automatically populated.
        void send(T value) {
            auto now = std::chrono::steady_clock::now();
            auto duration = now.time_since_epoch();
            this->send(Message<T> {
                .mMetadata = {
                    .mSequenceNumber = mQueue->mSequenceNumber.fetch_add(1, std::memory_order_relaxed),
                    .mPublishTime = static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(duration).count()),
                },
                .mPayload = std::move(value),
            });
        }

        /// Sends the given message to all subscribers.
        ///
        /// The caller is in charge of constructing the `Message` instance and populating its metadata.
        void send(Message<T> message) {
            {
                std::scoped_lock lock(mPoolPre->mMutex);
                for (auto &f : this->mPoolPre->mPool) {
                    f(message); // expect this may change the content
                }
            }

            auto head = std::make_shared<typename BroadcastQueue<T>::Entry>();

#if __cplusplus >= 202002L
            auto entry = mQueue->mHead.exchange(head, std::memory_order_relaxed);
            entry->mMessage = std::move(message);
            entry->mNext.store(head, std::memory_order_release);
            entry->mNext.notify_all();
#else
            auto entry = std::atomic_exchange_explicit(&mQueue->mHead, head, std::memory_order_relaxed);
            entry->mMessage = std::move(message);
            std::atomic_store_explicit(&entry->mNext, head, std::memory_order_release);
            entry->mCondVar.notify_all();
#endif

            {
                std::scoped_lock lock(mPoolPost->mMutex);
                for (auto &f : this->mPoolPost->mPool) {
                    f(entry->mMessage); // expect this may change the content
                }
            }
        }

        /// Returns the topic name of this publisher.
        std::string_view topic() const {
            return mQueue->topic();
        }

        /// Returns the number of messages this publisher has sent so far.
        uint64_t count() const {
            return this->mCount;
        }

    private:
        SharedBroadcastQueue<T> mQueue;
        SharedCallbackPool<T> mPoolPre, mPoolPost;
        uint64_t mCount = 0;
    };
}

#endif
