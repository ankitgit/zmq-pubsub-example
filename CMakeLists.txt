cmake_minimum_required(VERSION 3.15)
project(zmq_pubsub_example)

# Custome CMake find instructions and macros
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

# ZMQ
find_package(ZMQ REQUIRED)
if(ZMQ_FOUND)
    message(STATUS "ZMQ found ${ZMQ_INCLUDE_DIRS}")
else(ZMQ_FOUND)
    message(ERROR "ZMQ not found")
endif(ZMQ_FOUND)
include_directories(${ZMQ_INCLUDE_DIRS})
set(LIBRARIES ${LIBRARIES} ${ZMQ_LIBRARIES})

add_executable(zmq_pubsub_example src/main.cpp)
target_include_directories(zmq_pubsub_example PUBLIC ${LIBRARIES})
target_link_libraries(zmq_pubsub_example PUBLIC ${LIBRARIES})
