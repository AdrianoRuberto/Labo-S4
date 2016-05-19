cmake_minimum_required(VERSION 3.5)
project(16_Rivière)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Cont/Container.cpp Cont/Container.h Pers/Person.h Controller.cpp Controller.h Cont/Boat.cpp
        Cont/Boat.h Pers/Child.h Pers/Parent.h Pers/Thief.h Pers/Cop.h)
add_executable(16_Riviere ${SOURCE_FILES})