cmake_minimum_required(VERSION 3.3)
project(13_Matrices)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Test.cpp BinaryMatrice.cpp)
add_executable(13_Matrices ${SOURCE_FILES})

