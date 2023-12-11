#include "../include/VkCommon.h"

#include <iostream>
#include "BroadcastQueue.h"

void hello() {
    auto q = vkc::BroadcastQueue<int>::create();
    auto publisher = vkc::Publisher(q);
    auto subscriber = vkc::Subscriber(q);

    std::cout << "Hello, World!" << std::endl;
}
