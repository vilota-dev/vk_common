#include <stdexcept>
#include "vk_common/messaging/Registry.hpp"

int main() {
    vkc::Registry registry;
    auto publisher = registry.getPublisher<int>("test_topic");
    auto subscriber = registry.getSubscriber<int>("test_topic");
    
    publisher.send(123);
    publisher.send(456);
    auto message1 = subscriber.recv();
    auto message2 = subscriber.tryRecv();

    if (message1.mPayload != 123) {
        throw std::runtime_error("Received value 1 does not match sent value!");
    }
    if (message2.value().mPayload != 456) {
        throw std::runtime_error("Received value 2 does not match sent value!");
    }

    return 0;
}