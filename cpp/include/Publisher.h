#ifndef VK_COMMON_PUBLISHER_H
#define VK_COMMON_PUBLISHER_H

#include <memory>
#include "BroadcastQueue.h"

namespace vkc {
    template<typename T>
    class Publisher {
    public:
        explicit Publisher(SharedBroadcastQueue<T>& queue): mQueue(queue) {};

        void send(T value) {
            std::scoped_lock lock(this->mQueue->mMutex.lock());
            for (auto &queue : this->mQueue->mQueues) {
                queue.push(value);
            }
        }

    private:
        SharedBroadcastQueue<T> mQueue;
    };
}

#endif //VK_COMMON_PUBLISHER_H
