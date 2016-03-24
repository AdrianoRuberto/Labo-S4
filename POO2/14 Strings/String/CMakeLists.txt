cmake_minimum_required(VERSION 3.4)
project(Labo_string)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp cstring.cpp cstring.h)
add_executable(Labo_string ${SOURCE_FILES})