cmake_minimum_required(VERSION 3.3)
project(Tarjan)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.hxx)
add_executable(Tarjan ${SOURCE_FILES})