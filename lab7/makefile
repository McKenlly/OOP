CC = g++
CFLAGS = -std=c++11 -Wall -Werror -Wno-sign-compare -Wno-unused-result

PROG = lab7

all: allocator figure vector main clean

main: main.cpp TListItem.o TList.o TAllocationBlock.o TVectorItem.o TIterator.o Square.o Rectangle.o Trapezoid.o TVector.o
	$(CC) $(CFLAGS) -o $(PROG) main.cpp TListItem.o TList.o TAllocationBlock.o TVectorItem.o TIterator.o Square.o Rectangle.o Trapezoid.o TVector.o

allocator: ./TAllocateList/*
	$(CC) $(CFLAGS) -c ./TList/TListItem.cpp
	$(CC) $(CFLAGS) -c ./TList/TList.cpp
	$(CC) $(CFLAGS) -c ./TAllocateList/TAllocationBlock.cpp

figure: ./Figure/*
	$(CC) $(CFLAGS) -c ./Figure/Square.cpp
	$(CC) $(CFLAGS) -c ./Figure/Rectangle.cpp
	$(CC) $(CFLAGS) -c ./Figure/Trapezoid.cpp

vector: ./VectorForFigure/*
	$(CC) $(CFLAGS) -c ./VectorForFigure/TIterator.cpp
	$(CC) $(CFLAGS) -c ./VectorForFigure/TVectorItem.cpp
	$(CC) $(CFLAGS) -c ./VectorForFigure/TVector.cpp

clean:
	rm *.o
