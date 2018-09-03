cmake_minimum_required(VERSION 3.12)
project(mytriangle)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pg -g -lc ${CMAKE_CXX_FLAGS}")
#SET(LINK_FLAGS "-pg ${LINK_FLAGS}")
include_directories(.)

add_executable(mytriangle
        main.cpp
        tool.h
        Triangle.cpp
        Triangle.h)
