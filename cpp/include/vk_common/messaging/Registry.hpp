#ifndef VKC_REGISTRY_HPP
#define VKC_REGISTRY_HPP

#include <string>
#include <memory>
#include <map>

#include "Publisher.hpp"
#include "Subscriber.hpp"

namespace vkc {
    /// Represents a central place where all publisher and subscriber to a topic can be obtained.
    class Registry {
    public:
        Registry() = default;
        Registry(const Registry&) = delete;
        Registry& operator=(const Registry&) = delete;
        Registry(Registry&&) = delete;
        Registry& operator=(Registry&&) = delete;

        /// Constructs a subscriber to a topic.
        ///
        /// If the topic is already registered to a different message type than `T`, the returned 
        /// subscriber will not be "good" and cannot be used. You may use the `Subscriber::good` method to 
        /// check if the returned subscriber is "good". 
        template <typename T>
        Subscriber<T> getSubscriber(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            return Subscriber<T>(queue, topic);
        }

        /// Constructs a publisher to a topic.
        ///
        /// If the topic is already registered to a different message type than `T`, the returned 
        /// publisher will not be "good" and cannot be used. You may use the `Publisher::good` method to 
        /// check if the returned publisher is "good".
        template <typename T>
        Publisher<T> getPublisher(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            auto poolPre = getCallbackPoolPre<T>(topic);
            auto poolPost = getCallbackPoolPost<T>(topic);
            return Publisher<T>(queue, poolPre, poolPost, topic);
        }

        /// Register an early callback for a topic.
        ///
        /// An early callback is 
        ///
        /// If the topic is already registered to a different message type than `T`, `false` will
        /// be returned and the given callback will not be registered.
        template <typename T>
        bool registerCallbackPre(const std::string &topic, std::function<void(T&)> f) {
            auto pool = getCallbackPoolPre<T>(topic);

            if (pool != nullptr) {
                pool->addCallback(f);
                return true;
            } else {
                return false;
            }
        }

        /// Register a callback for a topic.
        ///
        /// If the topic is already registered to a different message type than `T`, `false` will
        /// be returned and the given callback will not be registered.
        template <typename T>
        bool registerCallbackPost(const std::string &topic, std::function<void(T&)> f) {
            auto pool = getCallbackPoolPost<T>(topic);
            
            if (pool != nullptr) {
                pool->addCallback(f);
                return true;
            } else {
                return false;
            }
        }

    private:
        template <typename T>
        SharedBroadcastQueue<T> getQueue(const std::string &topic) {
            if (queues.find(topic) == queues.end()) {
                queues.emplace(topic, BroadcastQueue<T>::create());
            }
            
            return std::dynamic_pointer_cast<BroadcastQueue<T>>(queues.at(topic));
        }

        template <typename T>
        SharedCallbackPool<T> getCallbackPoolPre(const std::string &topic) {
            if (poolPre.find(topic) == poolPre.end()) {
                poolPre.emplace(topic, CallbackPool<T>::create());
            }

            return std::dynamic_pointer_cast<CallbackPool<T>>(poolPre.at(topic));
        }

        template <typename T>
        SharedCallbackPool<T> getCallbackPoolPost(const std::string &topic) {
            if (poolPost.find(topic) == poolPost.end()) {
                poolPost.emplace(topic, CallbackPool<T>::create());
            }

            return std::dynamic_pointer_cast<CallbackPool<T>>(poolPost.at(topic));
        }

        std::map<std::string, std::shared_ptr<AbstractBQ>> queues;
        std::map<std::string, std::shared_ptr<AbstractCP>> poolPre, poolPost;
    };
}

#endif
