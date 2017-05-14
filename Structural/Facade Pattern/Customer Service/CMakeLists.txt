cmake_minimum_required(VERSION 3.5)
project(Customer_Service)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Customer_Service ${SOURCE_FILES})