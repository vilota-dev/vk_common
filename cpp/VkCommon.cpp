#include <vk-common/VkCommon.h>

#include <iostream>

int main() {
    //
    auto q = vkc::BroadcastQueue<int>::create();
    auto publisher = vkc::Publisher(q);
    auto subscriber = vkc::Subscriber(q);

    // Registry
    auto r = std::make_shared<vkc::Registry>();
    auto p = r->getPublisher<int>("topic1");
    auto s = r->getSubscriber<int>("topic2");

    // will result in runtime error
    // auto s2 = r->getSubscriber<std::string>("topic1");

    std::cout << "Hello, World!" << std::endl;

    return 0;
}

