CFLAGS=-Wall -pedantic -O2
CC=gcc

all: make_example

make_example: main.o io.o data.o
	$(CC) $(CFLAGS) -o make_example main.o io.o data.o

main.o: main.c io.h data.h
	$(CC) $(CFLAGS) -o main.o -c main.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -o io.o -c io.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -o data.o -c data.c

clear:
	rm *.o

pepito: 
	cp make_example ../make_example_exec
