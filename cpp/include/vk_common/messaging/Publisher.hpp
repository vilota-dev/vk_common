#ifndef VKC_PUBLISHER_HPP
#define VKC_PUBLISHER_HPP

#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    /// Represents a publisher to a message type.
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(SharedBroadcastQueue<T>& queue, SharedCallbackPool<T>& poolPre, SharedCallbackPool<T>& poolPost,
            const std::string& topic): mQueue(queue), mPoolPre(poolPre), mPoolPost(poolPost), mTopic(topic), mCount(0) {};
        Publisher(const Publisher&) = delete;
        Publisher(Publisher&& e) = default;
        Publisher& operator=(Publisher&& mE) = default;

        /// Returns whether this publisher can be used.
        ///
        /// If this method returns false, calling any other method of this object may invoke undefined behavior.
        bool good() {
            return this->mQueue != nullptr && 
                this->mPoolPre != nullptr && 
                this->mPoolPost != nullptr;
        }

        /// Send the given message to all subscribers.
        ///
        /// This method must not be called if this publisher is not "good" or it is undefined behavior.
        ///
        /// See the `good` method for more information.
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
        std::string topic() const {
            return mTopic;
        }

        /// Returns the number of messages this publisher has published.
        uint64_t count() const {
            return mCount;
        }

    private:
        SharedBroadcastQueue<T> mQueue;
        SharedCallbackPool<T> mPoolPre, mPoolPost;
        std::string mTopic;
        uint64_t mCount;
    };
}

#endif
