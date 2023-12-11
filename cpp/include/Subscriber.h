#ifndef VK_COMMON_SUBSCRIBER_H
#define VK_COMMON_SUBSCRIBER_H

#include <memory>
#include "BroadcastQueue.h"

namespace vkc {
    template<typename T>
    class Subscriber {
    public:
        T recv() {
            T result;
            while (!this->mQueue->pop(result)) {}
            return result;
        }

    private:
        explicit Subscriber(std::shared_ptr<BroadcastQueue<T>>& parent) {
            std::scoped_lock lock(parent->mMutex);
            auto queue = std::make_shared<tbb::concurrent_queue<T>>();
            parent->mQueues.push_back(queue);
            this->mQueue = queue;
        };

        std::shared_ptr<tbb::concurrent_bounded_queue<T>> mQueue;
    };
}

#endif //VK_COMMON_SUBSCRIBER_H
