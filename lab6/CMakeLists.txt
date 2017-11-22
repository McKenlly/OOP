cmake_minimum_required(VERSION 3.8)
project(lab6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  main.cpp  ./Figure/Rectangle.cpp ./Figure/Trapezoid.cpp ./Figure/Square.cpp ./VectorForFigure/TArray.cpp ./VectorForFigure/TArray.h
        ./VectorForFigure/TIterator.cpp ./TAllocateList/TAllocationBlock.cpp ./TAllocateList/TAllocationBlock.h
        ./VectorForFigure/TVectorItem.cpp TAllocateList/TList.cpp TAllocateList/TListItem.cpp)
add_executable(lab6 ${SOURCE_FILES})

#main.cpp ./Figure/Rectangle.cpp ./Figure/Trapezoid.cpp ./Figure/Square.cpp TArray.hpp TArray.h
#TIterator.cpp ./SmallObjectAllocation/FixedAllocator.cpp ./SmallObjectAllocation/Chunk.cpp
#TAllocationBlock.h TList.cpp TList.h TListItem.cpp TListItem.h