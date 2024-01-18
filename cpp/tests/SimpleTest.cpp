#include <stdexcept>
#include "vk_common/messaging/Registry.hpp"

void callback(const vkc::Message<int>& message) {
    // Rewrite first value.
    if (message.mMetadata.mSequenceNumber.value() == 0) {
        throw std::runtime_error("Callback received value 1 which does not match sent value!");
    }
}

int main() {
    vkc::Registry registry;
    auto publisher = registry.getPublisher<int>("test_topic");
    auto subscriber = registry.getSubscriber<int>("test_topic");

    registry.registerCallbackPre<int>("test_topic", callback);
    
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