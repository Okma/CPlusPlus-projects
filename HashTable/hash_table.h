#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <vector>
#include <string>
using namespace std;

class Hash_Table {
private:

	// Internal vectors for chaining collisions
	vector<string> * array;

	// The number of buckets in the table
	int size_of_table;

	// Hashing function
	int hash_function(string key);

public:

	// Hash Table with default size of 13
	Hash_Table();

	// Hash Table with given size
	Hash_Table(int size);

	// Retrieves the index of the item (search)
	int hash(string item);

	// Removes a given item from the table, returns if successful 
	bool searchItem(string item);

	// Adds a given item to the table
	void addItem(string item);

	// Returns the size of the has table
	int getSize();
};
#endif