CC=g++
CFLAGS = -Wall -g -O0 -Werror -I.
LIBFLAGS = -L. 

out6: main.o BinaryTree.o
	$(CC) $(LIBFLAGS) -o out6 main.o BinaryTree.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o main.o main.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) -c -o BinaryTree.o BinaryTree.cpp


