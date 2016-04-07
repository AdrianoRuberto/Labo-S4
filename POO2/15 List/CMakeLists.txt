cmake_minimum_required(VERSION 3.5)
project(15_List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp List.h Iterator.h Iterator.h)
add_executable(15_List ${SOURCE_FILES})