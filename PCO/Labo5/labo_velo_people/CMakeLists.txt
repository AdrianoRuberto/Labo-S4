cmake_minimum_required(VERSION 3.5)
project(labo_velo_people)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/bikinginterface.cpp
    src/bikinginterface.h
    src/display.cpp
    src/display.h
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/psleep.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Test)

add_executable(labo_velo_people ${SOURCE_FILES})

target_link_libraries(labo_velo_people Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Test)
