cmake_minimum_required(VERSION 3.15)
project(zmq_pubsub_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
#find cppzmq wrapper, installed by make of cppzmq
# - Try to find ZMQ
# Once done this will define
# ZMQ_FOUND - System has ZMQ
# ZMQ_INCLUDE_DIRS - The ZMQ include directories
# ZMQ_LIBRARIES - The libraries needed to use ZMQ
# ZMQ_DEFINITIONS - Compiler switches required for using ZMQ

find_path ( ZMQ_INCLUDE_DIR zmq.h )
find_library ( ZMQ_LIBRARY NAMES zmq )

set ( ZMQ_LIBRARIES ${ZMQ_LIBRARY} )
set ( ZMQ_INCLUDE_DIRS ${ZMQ_INCLUDE_DIR} )

include ( FindPackageHandleStandardArgs )
# handle the QUIETLY and REQUIRED arguments and set ZMQ_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args ( ZMQ DEFAULT_MSG ZMQ_LIBRARY ZMQ_INCLUDE_DIR )

find_package ( ZMQ REQUIRED )

add_executable(zmq_pubsub_example src/main.cpp)
