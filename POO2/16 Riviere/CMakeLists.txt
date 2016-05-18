cmake_minimum_required(VERSION 3.5)
project(16_Rivière)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Container.cpp Container.h Pers/Person.cpp Pers/Person.h Controller.cpp Controller.h Boat.cpp Boat.h Bank.cpp Bank.h Pers/Child.cpp Pers/Child.h Pers/Parent.cpp Pers/Parent.h Pers/Thief.cpp Pers/Thief.h Pers/Cop.cpp Pers/Cop.h)
add_executable(16_Riviere ${SOURCE_FILES})