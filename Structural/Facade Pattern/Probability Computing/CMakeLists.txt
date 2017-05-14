cmake_minimum_required(VERSION 3.5)
project(Facade_Calculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Facade_Calculator ${SOURCE_FILES})