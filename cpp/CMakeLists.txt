cmake_minimum_required(VERSION 3.27)
project(vk_common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(TBB REQUIRED)
message(STATUS "TBB FOUND ${TBB_VERSION_MAJOR}.${TBB_VERSION_MINOR} (interface version ${TBB_INTERFACE_VERSION}) headers in: ${TBB_INCLUDE_DIRS}")
if (TBB_INTERFACE_VERSION LESS 11004)
    # enable global_control header for earlier TBB versions (Ubuntu 16.04, 18.04)
    add_definitions(-DTBB_PREVIEW_GLOBAL_CONTROL)
endif()


add_subdirectory(src)

target_link_libraries(vk_common PRIVATE TBB::tbb)
