cmake_minimum_required(VERSION 3.12)
project(mytriangle)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mytriangle
        main.cpp
        tool.h
        Triangle.cpp
        Triangle.h)
