CC = g++
CFLAGS = -c

all: main

main: main.o 
	$(CC) -o main tDeque_main.o 
main.o: tDeque_main.cpp tDeque.h
	$(CC) $(CFLAGS) tDeque_main.cpp tDeque.h
clean: 
	rm -rf *.o