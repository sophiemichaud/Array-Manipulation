CFLAGS = -std=c99 -pedantic -Wall
CC = gcc -g

all: array_manipulation

array_manipulation:array_manipulation.o
	$(CC) $(CFLAGS) array_manipulation.o -o array_manipulation

array_manipulation.o:array_manipulation.c array_manipulation.h
	$(CC) $(CFLAGS) -c array_manipulation.c -o array_manipulation.o

clean:
	rm -i *.o array_manipulation
