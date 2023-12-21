#ifndef VK_COMMON_PUBLISHER_H
#define VK_COMMON_PUBLISHER_H

#include <memory>
#include "BroadcastQueue.h"
#include "CallbackPool.h"

namespace vkc {
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(SharedBroadcastQueue<T>& queue, SharedCallbackPool<T>& poolPre, SharedCallbackPool<T>& poolPost,
            const std::string& topic): mQueue(queue), mPoolPre(poolPre), mPoolPost(poolPost), mTopic(topic), mCount(0) {};
        Publisher(const Publisher&) = delete;

        // we have to bring back move constructor, as copy constructor is deleted explicitly
        // https://stackoverflow.com/a/37277554
        Publisher(Publisher&& e) = default;
        // Publisher& operator=(Publisher&& mE) = default;

        void send(T value) {

            // if there is callback in pre, calls the callback too
            // doing this save some threading creation with minimal latency impact, if designed properly
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

            // if there is callback in post, calls the callback too
            // doing this save some threading creation with minimal latency impact, if designed properly
            {
                std::scoped_lock<std::mutex> lock(this->mPoolPost->mMutex);
                for (auto &f : this->mPoolPost->mPool) {
                    f(value);
                }
            }

            mCount++;
        }

        std::string topic() const {
            return mTopic;
        }

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

#endif //VK_COMMON_PUBLISHER_H
