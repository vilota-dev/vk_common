#ifndef VKC_PUBLISHER_HPP
#define VKC_PUBLISHER_HPP

#include <typeinfo>
#include "BroadcastQueue.hpp"
#include "CallbackPool.hpp"

namespace vkc {
    class AbstractPublisher {
    public:
        virtual ~AbstractPublisher() = 0;

        /// Moves the message away from the given address and sends it.
        ///
        /// Note:
        /// The given pointer must contain a valid message object with the same underlying message type of 
        /// this publisher. The pointer itself must be aligned correctly, in accordance to the alignment 
        /// requirements of the message type of this publisher.
        virtual void sendDangerous(void* value) = 0;

        /// Returns the runtime type information of the message type of this publisher.
        virtual const std::type_info& messageType() const = 0;

        /// Returns the alignment requirement of the message type of this publisher.
        virtual size_t messageAlign() const = 0;

        /// Returns the size of the message type of this publisher.
        virtual size_t messageSize() const = 0;

        /// Returns the topic name of this publisher.
        inline const std::string& topic() const { return this->mTopic; }

        /// Returns the number of messages this publisher has sent so far.
        inline uint64_t count() const { return this->mCount; }

    protected:
        std::string mTopic;
        uint64_t mCount = 0;
    };

    /// Represents a publisher to a message type.
    template<typename T>
    class Publisher : public AbstractPublisher {
    public:
        explicit Publisher(
            SharedBroadcastQueue<T>& queue,
            SharedCallbackPool<T>& poolPre,
            SharedCallbackPool<T>& poolPost,
            const std::string& topic
        ): mQueue(queue), mPoolPre(poolPre), mPoolPost(poolPost) {
            this->mTopic = topic;
        };
        Publisher(const Publisher&) = delete;
        Publisher(Publisher&&) = default;
        Publisher& operator=(Publisher&&) = default;

        /// Send the given message to all subscribers.
        void send(T value) {
            {
                std::scoped_lock<std::mutex> lock(this->mPoolPre->mMutex);
                for (auto &f : this->mPoolPre->mPool) {
                    f(value); // expect this may change the content
                }
            }

            {
                std::scoped_lock<std::mutex> lock(this->mQueue->mMutex);
                for (auto &queue : this->mQueue->mQueues) {
                    queue->push(value);
                }
            }

            {
                std::scoped_lock<std::mutex> lock(this->mPoolPost->mMutex);
                for (auto &f : this->mPoolPost->mPool) {
                    f(value); // expect this may change the content
                }
            }

            mCount++;
        }

        void sendDangerous(void* value) override {
            this->send(std::move(*reinterpret_cast<T*>(value)));
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
        SharedBroadcastQueue<T> mQueue;
        SharedCallbackPool<T> mPoolPre, mPoolPost;
    };
}

#endif
