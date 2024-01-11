#ifndef VKC_SUBSCRIBER_HPP
#define VKC_SUBSCRIBER_HPP

#include <memory>
#include <algorithm>
#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    class AbstractSubscriber {
    public:
        virtual ~AbstractSubscriber() = 0;

        /// Block until there is an available message and then receives and writes it at the given address.
        ///
        /// Note:
        /// The given pointer must contain a valid message object (even if trivial) with the same underlying
        /// message type of this subscriber. The pointer itself must be aligned correctly, in accordance to
        /// the alignment requirements of the message type of this subscriber.
        virtual void recvDangerous(void* result) = 0;

        /// Receives and writes the message at the given address if there is one immediately available, or
        /// returns false otherwise.
        ///
        /// Note:
        /// The given pointer must contain a valid message object (even if trivial) with the same underlying
        /// message type of this subscriber. The pointer itself must be aligned correctly, in accordance to
        /// the alignment requirements of the message type of this subscriber.
        virtual bool tryRecvDangerous(void* result) = 0;

        /// Returns the runtime type information of the message type of this subscriber.
        virtual const std::type_info& messageType() const = 0;

        /// Returns the alignment requirement of the message type of this subscriber.
        virtual size_t messageAlign() const = 0;

        /// Returns the size of the message type of this subscriber.
        virtual size_t messageSize() const = 0;

        /// Returns the topic name of this subscriber.
        inline const std::string& topic() const { return this->mTopic; }

        /// Returns the number of messages this subscriber has received so far.
        inline uint64_t count() const { return mCount; }

    protected:
        std::string mTopic;
        uint64_t mCount;
    };

    /// Represents a subscriber to a message type.
    template<typename T>
    class Subscriber : public AbstractSubscriber {
    public:
        explicit Subscriber(SharedBroadcastQueue<T>& parent, const std::string& topic) : mParent(parent) {
            auto queue = std::make_shared<tbb::concurrent_bounded_queue<T>>();
            {
                std::scoped_lock lock(mParent->mMutex);
                mParent->mQueues.push_back(queue);
            }
            this->mQueue = queue;
            this->mTopic = topic;
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
            }
        }

        void recvDangerous(void* result) override {
            *reinterpret_cast<T*>(result) = std::move(this->recv());
        }

        bool tryRecvDangerous(void* result) override {
            return this->tryRecv(*reinterpret_cast<T*>(result));
        }

        const std::type_info& messageType() const override {
            return typeid(T);
        }
        
        size_t messageAlign() const override {
            return alignof(T);
        }

        size_t messageSize() const override {
            return sizeof(T);
        }

    private:
        SharedBroadcastQueue<T> mParent;
        std::shared_ptr<tbb::concurrent_bounded_queue<T>> mQueue;
    };
}

#endif
