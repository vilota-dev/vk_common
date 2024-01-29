#ifndef VKC_SUBSCRIBER_HPP
#define VKC_SUBSCRIBER_HPP

#include <atomic>
#include <memory>
#include <algorithm>
#include <optional>
#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    /// Represents a subscriber to a message type.
    template<typename T>
    class Subscriber {
    public:
        Subscriber(SharedBroadcastQueue<T>& parent)
            : mParent(parent),
              mCurrent(mParent->mHead),
              mCount(0) {};
        ~Subscriber() = default;
        Subscriber(const Subscriber&) = delete;
        Subscriber(Subscriber&&) = default;
        Subscriber& operator=(Subscriber&&) = default;

        /// Returns the topic name of this subscriber.
        std::string_view topic() const {
            return mParent->mTopic;
        }

        /// Returns the number of messages this subscriber has received so far.
        uint64_t count() const {
            return mCount;
        }

        /// Block until there is an available message and then receives and returns it.
        Message<T> recv() {
#if __cplusplus >= 202002L
            mCurrent->mNext.wait(nullptr, std::memory_order_acquire);
#else
            {
                std::unique_lock lock(mCurrent->mMutex);
                while (mCurrent->mNext == nullptr) {
                    mCurrent->mCondVar.wait(lock);
                }
            }
#endif
            mCount++;
            auto entry = mCurrent->mNext;
            std::swap(mCurrent, entry);
            return entry->mMessage.value();
        }

        /// Check if there is an available message and then receives and returns it.
        /// If there is no available message, this method returns a `std::nullopt`.
        std::optional<Message<T>> tryRecv() {
#if __cplusplus >= 202002L
            auto entry = mCurrent->mNext.load(std::memory_order_acquire);
#else
            std::unique_lock lock(mCurrent->mMutex);
            auto entry = mCurrent->mNext;
            lock.unlock();
#endif

            if (entry == nullptr) {
                return std::nullopt;
            } else {
                mCount++;
                std::swap(mCurrent, entry);
                return entry->mMessage.value();
            }
        }

    private:
        SharedBroadcastQueue<T> mParent;
        std::shared_ptr<typename BroadcastQueue<T>::Entry> mCurrent;
        uint64_t mCount;
    };
}

#endif
