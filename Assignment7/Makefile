CC = g++
CFLAGS = -Wall -Werror -I. -g
LIBFLAGS = -L.

all: hw7.out

hw7.out: main.o
	$(CC) $(LIBFLAGS) -o hw7.out main.o

main.o: BinarySearchTree.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f main.o
	
