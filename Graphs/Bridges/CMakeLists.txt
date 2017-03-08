cmake_minimum_required(VERSION 3.4)
project(Bridges)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Bridges ${SOURCE_FILES})