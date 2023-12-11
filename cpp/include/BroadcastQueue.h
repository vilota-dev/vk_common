#ifndef VK_COMMON_BROADCASTQUEUE_H
#define VK_COMMON_BROADCASTQUEUE_H

#include <memory>
#include <mutex>
#include <vector>
#include <tbb/concurrent_queue.h>

namespace vkc {
    template<typename T> class Publisher;
    template<typename T> class Subscriber;
    template<typename T> class BroadcastQueue;

    template<typename T>
    using SharedBroadcastQueue = std::shared_ptr<BroadcastQueue<T>>;

    template<typename T>
    class BroadcastQueue {
    public:
        BroadcastQueue() = default;
        BroadcastQueue(const BroadcastQueue<T>&) = delete;
        BroadcastQueue<T>& operator=(const BroadcastQueue<T>&) = delete;

        static SharedBroadcastQueue<T> create() {
            return std::make_shared<BroadcastQueue<T>>();
        }

        Publisher<T> publisher() { return Subscriber<T>(this); }
        Subscriber<T> subscriber() { return Publisher<T>(this); }

    private:
        friend class Publisher<T>;
        friend class Subscriber<T>;

        std::mutex mMutex;
        std::vector<std::shared_ptr<tbb::concurrent_bounded_queue<T>>> mQueues;
    };
}

#endif //VK_COMMON_BROADCASTQUEUE_H
