cmake_minimum_required(VERSION 3.5)
project(16_Rivière)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Cont/Container.cpp Cont/Container.h Pers/Person.h Pers/Person.cpp Controller.cpp Controller.h Cont/Boat.cpp
        Cont/Boat.h Pers/Child.cpp Pers/Child.h Pers/Parent.cpp Pers/Parent.h Pers/Thief.h Pers/Thief.cpp
        Pers/Cop.h Pers/Cop.cpp Pers/FamilyMember.cpp Pers/FamilyMember.h Dispatcher.cpp Dispatcher.h)
add_executable(16_Riviere ${SOURCE_FILES})