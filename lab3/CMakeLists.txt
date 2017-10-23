cmake_minimum_required(VERSION 3.8)
project(OOP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TArray.cpp Square.cpp Trapezoid.cpp Rectangle.cpp)
add_executable(OOP ${SOURCE_FILES})