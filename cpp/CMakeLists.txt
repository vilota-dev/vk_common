cmake_minimum_required(VERSION 3.16)
project(vk_common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#=====================================================
# Dependencies.
#======================================================

# static linking capnproto
set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
find_package(CapnProto 1.0.2 REQUIRED)


#=====================================================
# CapNProto Compilation
#======================================================

set(VKC_CAPNP_SCHEMA_FILES
        header.capnp
        vector3.capnp
        imu.capnp
        imulist.capnp
        image.capnp
        odometry3d.capnp
        disparity.capnp
        so3.capnp
        se3.capnp
        detection2d.capnp
        cameracontrol.capnp
        cameraintrinsic.capnp
        sensorextrinsic.capnp
        vector2.capnp
        tagdetection.capnp
        twist3.capnp
        flow2d.capnp
)

set(VKC_CAPNP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_common/capnp")
set(VKC_CAPNP_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/capnp")

file(MAKE_DIRECTORY ${VKC_CAPNP_INCLUDE_DIR})
file(MAKE_DIRECTORY ${VKC_CAPNP_OUTPUT_DIR})

set(VKC_CAPNP_HEADERS)
set(VKC_CAPNP_SOURCES)

foreach(VKC_CAPNP_SCHEMA_FILE ${VKC_CAPNP_SCHEMA_FILES})
        get_filename_component(VKC_CAPNP_SCHEMA_FILE_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../capnp" ABSOLUTE)
        get_filename_component(VKC_CAPNP_SCHEMA_FILE_PATH "${VKC_CAPNP_SCHEMA_FILE_PREFIX}/${VKC_CAPNP_SCHEMA_FILE}" ABSOLUTE)

        if(NOT EXISTS "${VKC_CAPNP_SCHEMA_FILE_PATH}")
                message(FATAL_ERROR "Cap'n Proto schema file '${VKC_CAPNP_SCHEMA_FILE_PATH}' does not exist!")
        endif()

        # https://stackoverflow.com/questions/18590445/cmake-custom-command-to-copy-and-rename

        set(VKC_CAPNP_COMPILE "capnp")

        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++" "${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h"
                COMMAND "${VKC_CAPNP_COMPILE}"
                ARGS compile
                        --output=c++:${CMAKE_CURRENT_BINARY_DIR}
                        --src-prefix=${VKC_CAPNP_SCHEMA_FILE_PREFIX}
                        --import-path=${VKC_CAPNP_SCHEMA_FILE_PREFIX}
                        --import-path=${CAPNP_INCLUDE_DIRECTORY}
                        ${VKC_CAPNP_SCHEMA_FILE_PATH}
                DEPENDS "${VKC_CAPNP_SCHEMA_FILE_PATH}"
                COMMENT "Compiling Cap'n Proto schema ${VKC_CAPNP_SCHEMA_FILE}"
                VERBATIM
        )

        add_custom_command(
                OUTPUT "${VKC_CAPNP_INCLUDE_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h"
                COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h "${VKC_CAPNP_INCLUDE_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h"
                DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h"
                VERBATIM
        )

        add_custom_command(
                OUTPUT "${VKC_CAPNP_OUTPUT_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++"
                COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++ "${VKC_CAPNP_OUTPUT_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++"
                DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++"
                VERBATIM
        )

        list(APPEND VKC_CAPNP_HEADERS "${VKC_CAPNP_INCLUDE_DIR}/${VKC_CAPNP_SCHEMA_FILE}.h")
        list(APPEND VKC_CAPNP_SOURCES "${VKC_CAPNP_OUTPUT_DIR}/${VKC_CAPNP_SCHEMA_FILE}.c++")
endforeach()

# set_source_files_properties(${VKC_CAPNP_HEADERS} ${VKC_CAPNP_SOURCES} PROPERTIES GENERATED TRUE)

#=====================================================
# Targets
#======================================================

add_library(vk_common STATIC
        ${VKC_CAPNP_HEADERS}
        ${VKC_CAPNP_SOURCES}
        "include/vk_common/capnp/Shared.hpp"
        "include/vk_common/messaging/Message.hpp"
        "include/vk_common/messaging/BroadcastQueue.hpp"
        "include/vk_common/messaging/CallbackPool.hpp"
        "include/vk_common/messaging/Publisher.hpp"
        "include/vk_common/messaging/Subscriber.hpp"
        "include/vk_common/messaging/Registry.hpp"
)
target_include_directories(vk_common 
        PRIVATE include/vk_common/capnp
        PUBLIC include)
target_link_libraries(vk_common
        PUBLIC CapnProto::capnp)

add_executable(vk_test "tests/SimpleTest.cpp")
target_link_libraries(vk_test PRIVATE vk_common)
