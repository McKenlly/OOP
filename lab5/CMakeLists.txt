cmake_minimum_required(VERSION 3.8)
project(lab5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Figure.h Square.cpp Trapezoid.cpp Rectangle.cpp TArray.hpp TArray.h )
add_executable(lab5 ${SOURCE_FILES})