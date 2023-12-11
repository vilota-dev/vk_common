#include "../include/VkCommon.h"

#include <iostream>
#include "BroadcastQueue.h"

void hello() {
    auto q = vkc::BroadcastQueue<int>::create();

    std::cout << "Hello, World!" << std::endl;
}
