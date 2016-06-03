all: main

main: hash_table main.o
	g++ -o hash-table hash_table.o main.o
	
main.o: main.cpp
	g++ -c main.cpp
	
hash_table: hash_table.h hash_table.cpp
	g++ -c -std=c++11 hash_table.h hash_table.cpp