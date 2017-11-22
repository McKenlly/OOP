CC = g++
CFLAGS = -g -std=c++11 -Wall -Werror -Wno-sign-compare -Wno-unused-result
FILES = main1.cpp TAllocationBlock.cpp TListItem.cpp TList.cpp
PROG = lab6

all: allocator figure vector main clean

main: $(FILES)
	$(CC) $(CFLAGS) -o $(PROG) main.cpp Square.o Rectangle.o Trapezoid.o TListItem.o TAllocationBlock.o TList.o TIterator.o TVectorItem.o TArray.o

allocator: ./TAllocateList/*
	$(CC) $(CFLAGS) -c ./TAllocateList/TListItem.cpp
	$(CC) $(CFLAGS) -c ./TAllocateList/TList.cpp # TListItem.o
	$(CC) $(CFLAGS) -c ./TAllocateList/TAllocationBlock.cpp #TList.o

figure: ./Figure/*
	$(CC) $(CFLAGS) -c ./Figure/Square.cpp
	$(CC) $(CFLAGS) -c ./Figure/Rectangle.cpp
	$(CC) $(CFLAGS) -c ./Figure/Trapezoid.cpp

vector: ./VectorForFigure/*
	$(CC) $(CFLAGS) -c ./VectorForFigure/TIterator.cpp
	$(CC) $(CFLAGS) -c ./VectorForFigure/TVectorItem.cpp
	$(CC) $(CFLAGS) -c ./VectorForFigure/TArray.hpp

clean:
	rm *.o
