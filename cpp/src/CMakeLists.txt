set(HEADERS_LIST
        ../include/VkCommon.h
        ../include/BroadcastQueue.h
        ../include/Publisher.h
        ../include/Subscriber.h
)

add_library(vk_common STATIC
        ${HEADERS_LIST}
        VkCommon.cpp
)

target_include_directories(vk_common PUBLIC ../include)

