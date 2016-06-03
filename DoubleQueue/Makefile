CC = g++
CFLAGS = -c

all: main

main: main.o deque.o 
	$(CC) -o main sDeque.o sDeque_main.o 
main.o: sDeque_main.cpp
	$(CC) $(CFLAGS) sDeque_main.cpp
deque.o: sDeque.cpp
	$(CC) $(CFLAGS) sDeque.cpp
clean: 
	rm -rf *.o