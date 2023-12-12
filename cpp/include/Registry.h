#ifndef VK_COMMON_REGISTRY_H
#define VK_COMMON_REGISTRY_H

#include <string>
#include <memory>
#include <map>

#include "Publisher.h"
#include "Subscriber.h"

namespace vkc {
    class Registry {
    public:
        Registry() = default;
        Registry(const Registry&) = delete;
        Registry& operator=(const Registry&) = delete;

        template <typename T>
        Subscriber<T> getSubscriber(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            return Subscriber<T>(queue);
        }

        template <typename T>
        Publisher<T> getPublisher(const std::string &topic) {
            auto queue = getQueue<T>(topic);
            return Publisher<T>(queue);
        }

    private:
        template <typename T>
        SharedBroadcastQueue<T> getQueue(const std::string &topic) {
            if (queues.find(topic) == queues.end()) {
                queues.emplace(topic, BroadcastQueue<T>::create());
            }
            try {
                return std::dynamic_pointer_cast<BroadcastQueue<T>>(queues.at(topic));
            } catch (std::bad_cast &e) {
                throw std::runtime_error("[registry] topic - " + topic + ": already exists, but with a different type");
            }
        }

        std::map<std::string, std::shared_ptr<AbstractBQ>> queues;
    };
}

#endif //VK_COMMON_REGISTRY_H
