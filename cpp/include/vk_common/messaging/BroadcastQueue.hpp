#ifndef VKC_BROADCASTQUEUE_HPP
#define VKC_BROADCASTQUEUE_HPP

#if __cplusplus < 202002L
#include <mutex>
#include <condition_variable>
#endif

#include <atomic>
#include <memory>
#include <optional>
#include <string_view>

#include "Message.hpp"

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
        BroadcastQueue(const BroadcastQueue<T>&) = delete;
        BroadcastQueue<T>& operator=(const BroadcastQueue<T>&) = delete;

        /// Return the topic of this queue.
        std::string_view topic() const {
            return mTopic;
        }

        static SharedBroadcastQueue<T> create(const std::string_view topic) {
            auto queue = std::shared_ptr<BroadcastQueue<T>>(new BroadcastQueue());
            queue->mTopic = topic;
            queue->mSequenceNumber = 0;
            queue->mHead = std::make_shared<Entry>();
            return queue;
        }

    private:
        BroadcastQueue() = default;

        friend class Publisher<T>;
        friend class Subscriber<T>;

        class Entry {
            friend class Publisher<T>;
            friend class Subscriber<T>;

            std::optional<Message<T>> mMessage;

#if __cplusplus >= 202002L
            std::atomic<std::shared_ptr<Entry>> mNext;  //< Pointer to the next message in the queue.
                                                        //< When this is `nullptr`, mMessage does not contain a value.
                                                        //< This will only ever be written once.
#else
            std::mutex mMutex;                  //< Used in combination with condition variable to signal next message is ready.
            std::condition_variable mCondVar;   //< Used in combination with mutex to signal next message is ready.
            std::shared_ptr<Entry> mNext;       //< Pointer to the next message in the queue.
                                                //< This must be accessed atomically!
                                                //< This will only ever be written once.
#endif
        }; // Entry

        std::string mTopic;
        std::atomic<uint64_t> mSequenceNumber;

#if __cplusplus >= 202002L
        std::atomic<std::shared_ptr<Entry>> mHead;
#else
        std::shared_ptr<Entry> mHead;
#endif
    };
}

#endif
