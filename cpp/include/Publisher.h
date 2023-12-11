#ifndef VK_COMMON_PUBLISHER_H
#define VK_COMMON_PUBLISHER_H

#include <memory>
#include "BroadcastQueue.h"

namespace vkc {
    template<typename T>
    class Publisher {
    public:
        void send(T value) {
            std::scoped_lock lock(this->mQueue->mMutex.lock());
            for (auto &queue : this->mQueue->mQueues) {
                queue.push(value);
            }
        }

    private:
        explicit Publisher(std::shared_ptr<BroadcastQueue<T>>& queue): mQueue(queue) {};

        std::shared_ptr<BroadcastQueue<T>> mQueue;
    };
}

#endif //VK_COMMON_PUBLISHER_H
