#ifndef VKC_SUBSCRIBER_HPP
#define VKC_SUBSCRIBER_HPP

#include <memory>
#include <algorithm>
#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    /// Represents a subscriber to a message type.
    template<typename T>
    class Subscriber {
    public:
        explicit Subscriber(SharedBroadcastQueue<T>& parent, const std::string_view topic) : mParent(parent), mTopic(topic) {
            auto queue = std::make_shared<tbb::concurrent_bounded_queue<T>>();
            {
                std::scoped_lock lock(mParent->mMutex);
                mParent->mQueues.push_back(queue);
            }
            this->mQueue = queue;
        };
        ~Subscriber() {
            if (mParent) {
                std::scoped_lock lock(mParent->mMutex);
                auto it = std::find(mParent->mQueues.begin(), mParent->mQueues.end(), this->mQueue);
                if (it != mParent->mQueues.end()) {
                    mParent->mQueues.erase(it);
                }
            }
        }
        Subscriber(const Subscriber&) = delete;
        Subscriber(Subscriber&&) = default;
        Subscriber& operator=(Subscriber&&) = default;

        /// Block until there is an available message and then receives and returns it.
        T recv() {
            T result;
            this->mQueue->pop(result);
            this->mCount++;
            return result;
        }

        /// Receives and writes the message at the given address if there is one immediately available, or
        /// returns false otherwise.
        bool tryRecv(T& result) {
            if (this->mQueue->try_pop(result)) {
                this->mCount++;
                return true;
            }
            return false;
        }

        /// Returns the topic name of this subscriber.
        std::string_view topic() const {
            return this->mTopic;
        }

        /// Returns the number of messages this subscriber has received so far.
        uint64_t count() const {
            return mCount;
        }

    private:
        SharedBroadcastQueue<T> mParent;
        std::shared_ptr<tbb::concurrent_bounded_queue<T>> mQueue;
        std::string mTopic;
        uint64_t mCount;
    };
}

#endif
