all: main

main: main.o
	g++ -o Floyd-Warshall main.o 

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o