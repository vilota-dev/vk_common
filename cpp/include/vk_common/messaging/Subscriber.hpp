#ifndef VKC_SUBSCRIBER_HPP
#define VKC_SUBSCRIBER_HPP

#include <memory>
#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    class AbstractSubscriber {
    public:
        virtual ~AbstractSubscriber() = 0;
    };

    /// Represents a subscriber to a message type.
    template<typename T>
    class Subscriber : public AbstractSubscriber {
    public:
        explicit Subscriber(SharedBroadcastQueue<T>& parent, const std::string& topic) : mParent(parent), mTopic(topic), mCount(0) {
            std::scoped_lock lock(parent->mMutex);
            auto queue = std::make_shared<tbb::concurrent_bounded_queue<T>>();
            parent->mQueues.push_back(queue);
            this->mQueue = queue;
        };
        ~Subscriber() {
            std::scoped_lock lock(mParent->mMutex);
            auto it = find(mParent->mQueues.begin(), mParent->mQueues.end(), this->mQueue);
            if (it != mParent->mQueues.end()) {
                mParent->mQueues.erase(it);
            }
        }
        Subscriber(const Subscriber&) = delete;
        Subscriber(Subscriber&& e) = default;
        Subscriber& operator=(Subscriber&& mE) = default;

        /// Returns whether this subscriber can be used.
        ///
        /// If this method returns false, calling any other method of this object may invoke undefined behavior.
        bool good() {
            return this->mQueue != nullptr;
        }

        /// Block until there is an available message and then returns it.
        ///
        /// This method must not be called if this subscriber is not "good" or it is undefined behavior.
        ///
        /// See the `good` method for more information.
        T recv() {
            T result;
            this->mQueue->pop(result);
            mCount++;
            return result;
        }

        /// Try to receive a message now or returns false.
        ///
        /// This method must not be called if this subscriber is not "good" or it is undefined behavior.
        ///
        /// See the `good` method for more information.
        bool try_recv(T& result) {
            return this->mQueue->try_pop(result);
        }

        /// Returns the topic name of this subscriber.
        std::string topic() const {
            return mTopic;
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
