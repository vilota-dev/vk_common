#ifndef VK_COMMON_PUBLISHER_H
#define VK_COMMON_PUBLISHER_H

#include <memory>
#include "BroadcastQueue.h"

namespace vkc {
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(SharedBroadcastQueue<T>& queue, const std::string& topic): mQueue(queue), mTopic(topic), mCount(0) {};
        Publisher(const Publisher&) = delete;

        // we have to bring back move constructor, as copy constructor is deleted explicitly
        // https://stackoverflow.com/a/37277554
        Publisher(Publisher&& e) = default;
        // Publisher& operator=(Publisher&& mE) = default;

        void send(T value) {
            std::scoped_lock<std::mutex> lock(this->mQueue->mMutex);
            for (auto &queue : this->mQueue->mQueues) {
                queue->push(value);
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
        std::string mTopic;
        uint64_t mCount;
    };
}

#endif //VK_COMMON_PUBLISHER_H
