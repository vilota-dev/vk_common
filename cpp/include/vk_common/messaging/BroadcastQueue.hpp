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

    class AbstractBQ {
    public:
        virtual ~AbstractBQ() = default;
    };

    template<typename T>
    class BroadcastQueue : public AbstractBQ {
    public:
        // BroadcastQueue() = default;
        BroadcastQueue(const BroadcastQueue<T>&) = delete;
        BroadcastQueue<T>& operator=(const BroadcastQueue<T>&) = delete;

        static SharedBroadcastQueue<T> create() {
            // using raw pointer initializer to make private constructor work here
            // https://stackoverflow.com/a/71379724
            return std::shared_ptr<BroadcastQueue<T>>(new BroadcastQueue());
            // return std::make_shared<BroadcastQueue<T>>();
        }

    private:
        BroadcastQueue() = default;

        friend class Publisher<T>;
        friend class Subscriber<T>;

        std::mutex mMutex;
        std::vector<std::shared_ptr<tbb::concurrent_bounded_queue<T>>> mQueues;
    };
}

#endif //VK_COMMON_BROADCASTQUEUE_H
