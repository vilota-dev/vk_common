cmake_minimum_required(VERSION 3.25)
project(vk_common_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(include/)

add_executable(vk_common_test VkCommon.cpp)
target_link_libraries(vk_common_test vk_common)