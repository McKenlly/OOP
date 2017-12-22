cmake_minimum_required(VERSION 3.8)
project(lab9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        figure.h
        main.cpp
        rectangle.cpp
        rectangle.h
        square.cpp
        square.h
        TAllocationBlock.cpp
        TAllocationBlock.h
        TIterator.h
        TList.cpp
        TList.h
        TListItem.cpp
        TListItem.h
        trapeze.cpp
        trapeze.h
        TStack.cpp
        TStack.h
        TStackItem.cpp
        TStackItem.h)

add_executable(lab9 ${SOURCE_FILES})