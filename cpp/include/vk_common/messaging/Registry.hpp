#ifndef VK_COMMON_REGISTRY_H
#define VK_COMMON_REGISTRY_H

#include <string>
#include <memory>
#include <map>

#include "Publisher.hpp"
#include "Subscriber.hpp"

namespace vkc {
    class Registry {
    public:
        Registry() = default;
        Registry(const Registry&) = delete;
        Registry& operator=(const Registry&) = delete;
        Registry(Registry&&) = delete;
        Registry& operator=(Registry&&) = delete;

        template <typename T>
        Subscriber<T> getSubscriber(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            return Subscriber<T>(queue, topic);
        }

        template <typename T>
        Publisher<T> getPublisher(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            auto poolPre = getCallbackPoolPre<T>(topic);
            auto poolPost = getCallbackPoolPost<T>(topic);
            return Publisher<T>(queue, poolPre, poolPost, topic);
        }

        template <typename T>
        void registerCallbackPre(const std::string &topic, std::function<void(T&)> f) {
            auto pool = getCallbackPoolPre<T>(topic);
            pool->addCallback(f);
        }

        template <typename T>
        void registerCallbackPost(const std::string &topic, std::function<void(T&)> f) {
            auto pool = getCallbackPoolPost<T>(topic);
            pool->addCallback(f);
        }

    private:
        template <typename T>
        SharedBroadcastQueue<T> getQueue(const std::string &topic) {
            if (queues.find(topic) == queues.end()) {
                queues.emplace(topic, BroadcastQueue<T>::create());
            }
            try {
                // HM: i believe the cast will not throw, instead it returns a null pointer
                return std::dynamic_pointer_cast<BroadcastQueue<T>>(queues.at(topic));
            } catch (std::bad_cast &e) {
                // TODO: investigate - doesn't seem to be throwing?
                throw std::runtime_error("[registry] topic - " + topic + ": already exists, but with a different type");
            }
        }

        template <typename T>
        SharedCallbackPool<T> getCallbackPoolPre(const std::string &topic) {
            if (poolPre.find(topic) == poolPre.end()) {
                poolPre.emplace(topic, CallbackPool<T>::create());
            }
            try {
                // HM: i believe the cast will not throw, instead it returns a null pointer
                return std::dynamic_pointer_cast<CallbackPool<T>>(poolPre.at(topic));
            } catch (std::bad_cast &e) {
                // TODO: investigate - doesn't seem to be throwing?
                throw std::runtime_error("[registry] topic - " + topic + ": already exists, but with a different type");
            }
        }

        template <typename T>
        SharedCallbackPool<T> getCallbackPoolPost(const std::string &topic) {
            if (poolPost.find(topic) == poolPost.end()) {
                poolPost.emplace(topic, CallbackPool<T>::create());
            }
            try {
                // HM: i believe the cast will not throw, instead it returns a null pointer
                return std::dynamic_pointer_cast<CallbackPool<T>>(poolPost.at(topic));
            } catch (std::bad_cast &e) {
                // TODO: investigate - doesn't seem to be throwing?
                throw std::runtime_error("[registry] topic - " + topic + ": already exists, but with a different type");
            }
        }

        std::map<std::string, std::shared_ptr<AbstractBQ>> queues;
        std::map<std::string, std::shared_ptr<AbstractCP>> poolPre, poolPost;
    };
}

#endif //VK_COMMON_REGISTRY_H
