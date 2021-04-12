cmake_minimum_required(VERSION 2.8)

project(Property)

set(TARGET_PATH ${CMAKE_CURRENT_SOURCE_DIR})

message("project path: " ${TARGET_PATH})

message("default complie")
set(EXECUTABLE_OUTPUT_PATH ${TARGET_PATH}/out)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(LIBRARY_OUTPUT_PATH ${TARGET_PATH}/lib)

message("CMAKE_INCLUDE_PATH: " ${CMAKE_INCLUDE_PATH})
message("MIDDLE_LIB: " ${MIDDLE_LIB})

set(CMAKE_FIND_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR} /opt)

# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -g  -Wimplicit-int -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g  -std=c++11 -fno-strict-aliasing -fpermissive")
message("CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

add_definitions(-D_GUN_SOURCE)

# include
include_directories(
    ${TARGET_PATH}/include
)

set (PROPERTY_SRC
	${TARGET_PATH}/property/properties.c
    ${TARGET_PATH}/property/system_properties.c
    ${TARGET_PATH}/property/system_properties_compat.c
    ${TARGET_PATH}/property/util.c
    ${TARGET_PATH}/property/socket_inaddr_any_server.c
    ${TARGET_PATH}/property/socket_local_client.c
    ${TARGET_PATH}/property/socket_local_server.c
    ${TARGET_PATH}/property/socket_loopback_client.c
    ${TARGET_PATH}/property/socket_loopback_server.c
    ${TARGET_PATH}/property/socket_network_client.c
    ${TARGET_PATH}/property/sockets.c
)

# Property service
aux_source_directory(${TARGET_PATH}/property/server PROPER_SERVICE)

# Property service bin
add_executable(ProperServer ${PROPER_SERVICE})

# gtest lib
add_library(property SHARED ${PROPERTY_SRC})

# Link
target_link_libraries(ProperServer c rt pthread property dl)