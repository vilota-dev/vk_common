cmake_minimum_required(VERSION 3.16)
project(vk_common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#=====================================================
# Dependencies.
#======================================================

# static linking capnproto
set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
find_package(CapnProto REQUIRED)


#=====================================================
# CapNProto Compilation
#======================================================

set(VKC_CAPNP_SCHEMA_FILES
        header.capnp
        vector3.capnp
        imu.capnp
        imulist.capnp
        image.capnp
        disparity.capnp
        so3.capnp
        se3.capnp
        detection2d.capnp
        cameracontrol.capnp
        cameraintrinsic.capnp
        sensorextrinsic.capnp
        vector2.capnp
        tagdetection.capnp
        flow2d.capnp
)

set(VKC_CAPNP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_common/capnp")
set(VKC_CAPNP_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/capnp")

file(MAKE_DIRECTORY ${VKC_CAPNP_INCLUDE_DIR})
file(MAKE_DIRECTORY ${VKC_CAPNP_OUTPUT_DIR})

foreach(VKC_CAPNP_SCHEMA_FILE ${VKC_CAPNP_SCHEMA_FILES})
        get_filename_component(VKC_CAPNP_SCHEMA_FILE_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../capnp" ABSOLUTE)
        get_filename_component(VKC_CAPNP_SCHEMA_FILE_PATH "${VKC_CAPNP_SCHEMA_FILE_PREFIX}/${VKC_CAPNP_SCHEMA_FILE}" ABSOLUTE)

        if(NOT EXISTS "${VKC_CAPNP_SCHEMA_FILE_PATH}")
                message(FATAL_ERROR "Cap'n Proto schema file '${VKC_CAPNP_SCHEMA_FILE_PATH}' does not exist!")
        endif()

        set(VKC_CAPNP_COMPILE "capnp")
        list(APPEND VKC_CAPNP_COMPILE "compile"
                "--output=c++:${VKC_CAPNP_OUTPUT_DIR}"
                "--src-prefix=${VKC_CAPNP_SCHEMA_FILE_PREFIX}"
                "--import-path=${VKC_CAPNP_SCHEMA_FILE_PREFIX}"
                "--import-path=${CAPNP_INCLUDE_DIRECTORY}"
                "${VKC_CAPNP_SCHEMA_FILE_PATH}")

        execute_process(COMMAND ${VKC_CAPNP_COMPILE})

        file(RENAME "${VKC_CAPNP_OUTPUT_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h" "${VKC_CAPNP_INCLUDE_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h")
        list(APPEND VKC_CAPNP_HEADERS "${VKC_CAPNP_INCLUDE_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h")
        list(APPEND VKC_CAPNP_SOURCES "${VKC_CAPNP_OUTPUT_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++")
endforeach()

#=====================================================
# Targets
#======================================================

add_library(vk_common STATIC
        ${VKC_CAPNP_HEADERS}
        ${VKC_CAPNP_SOURCES}
        "include/vk_common/messaging/BroadcastQueue.hpp"
        "include/vk_common/messaging/CallbackPool.hpp"
        "include/vk_common/messaging/Publisher.hpp"
        "include/vk_common/messaging/Subscriber.hpp"
        "include/vk_common/messaging/Registry.hpp"
)
target_include_directories(vk_common 
        PRIVATE include/vk_common/capnp
        PUBLIC include)