cmake_minimum_required(VERSION 3.8)
project(lab7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        figure.h
        main.cpp
        pentagon.cpp
        pentagon.h
        rhomb.cpp
        rhomb.h
        TAllocator.cpp
        TAllocator.h
        TIterator.hpp
        TList.h
        TList.hpp
        trapeze.cpp
        trapeze.h
        TStack.h
        TStack.hpp)

add_executable(lab7 ${SOURCE_FILES})