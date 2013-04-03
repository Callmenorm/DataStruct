CC=g++
CFLAGS = -Wall -g -O0 -Werror -I.
LIBFLAGS = -L. 

out6: main.o BinaryTree.h
	$(CC) $(LIBFLAGS) -o out6 main.o

main.o: main.cpp BinaryTree.h
	$(CC) $(CFLAGS) -c -o main.o main.cpp

