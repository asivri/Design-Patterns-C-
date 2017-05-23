cmake_minimum_required(VERSION 3.5)
project(Observe_My_Roomie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Observe_My_Roomie ${SOURCE_FILES})