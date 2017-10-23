cmake_minimum_required(VERSION 3.8)
project(OOP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Rectangle.cpp Rectangle.h Trapezoid.cpp Trapezoid.h Square.cpp Square.h)
add_executable(OOP ${SOURCE_FILES})