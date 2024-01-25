#ifndef VKC_PUBLISHER_HPP
#define VKC_PUBLISHER_HPP

#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    /// Represents a publisher to a message type.
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(
            SharedBroadcastQueue<T>& queue,
            SharedCallbackPool<T>& poolPre,
            SharedCallbackPool<T>& poolPost,
            const std::string_view topic
        ): mQueue(queue), mPoolPre(poolPre), mPoolPost(poolPost), mTopic(topic), mCount(0) {}
        Publisher(const Publisher&) = delete;
        Publisher(Publisher&&) = default;
        Publisher& operator=(Publisher&&) = default;

        /// Send the given message to all subscribers.
        void send(T value) {
            {
                std::scoped_lock<std::mutex> lock(this->mPoolPre->mMutex);
                for (auto &f : this->mPoolPre->mPool) {
                    f(value); // expect this may change the content
                }
            }

            {
                std::scoped_lock<std::mutex> lock(this->mQueue->mMutex);
                for (auto &queue : this->mQueue->mQueues) {
                    queue->push(value);
                }
            }

            {
                std::scoped_lock<std::mutex> lock(this->mPoolPost->mMutex);
                for (auto &f : this->mPoolPost->mPool) {
                    f(value); // expect this may change the content
                }
            }

            mCount++;
        }

        /// Returns the topic name of this publisher.
        std::string_view topic() const {
            return this->mTopic; 
        }

        /// Returns the number of messages this publisher has sent so far.
        uint64_t count() const {
            return this->mCount;
        }

    private:
        SharedBroadcastQueue<T> mQueue;
        SharedCallbackPool<T> mPoolPre, mPoolPost;
        std::string mTopic;
        uint64_t mCount;
    };
}

#endif
