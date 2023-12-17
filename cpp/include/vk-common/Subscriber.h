#ifndef VK_COMMON_SUBSCRIBER_H
#define VK_COMMON_SUBSCRIBER_H

#include <memory>
#include "BroadcastQueue.h"
#include "CallbackPool.h"

namespace vkc {
    template<typename T>
    class Subscriber {
    public:
        explicit Subscriber(SharedBroadcastQueue<T>& parent, const std::string& topic) : mTopic(topic), mCount(0) {
            std::scoped_lock lock(parent->mMutex);
            auto queue = std::make_shared<tbb::concurrent_bounded_queue<T>>();
            parent->mQueues.push_back(queue);
            this->mQueue = queue;
        };
        Subscriber(const Subscriber&) = delete;
        Subscriber(Subscriber&& e) = default;

        T recv() {
            T result;
            this->mQueue->pop(result);
            mCount++;
            return result;
        }

        bool try_recv(T& result) {
            return this->mQueue->try_pop(result);
        }

        std::string topic() const {
            return mTopic;
        }

        uint64_t count() const {
            return mCount;
        }

    private:
        std::shared_ptr<tbb::concurrent_bounded_queue<T>> mQueue;
        std::string mTopic;
        uint64_t mCount;
    };
}

#endif //VK_COMMON_SUBSCRIBER_H
