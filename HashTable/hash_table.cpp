#include "hash_table.h"

// Private hashing function
int Hash_Table::hash_function(string key) {
	int index = 0;
	for (int i = 0; i < key.length(); i++)
		index += key[i];
	return index % size_of_table;
}

// Default to 13, reduce # of collisions
Hash_Table::Hash_Table() {
	array = new vector<string>[13];
	size_of_table = 13;
}

// Parametrized constructor; init to size
Hash_Table::Hash_Table(int size) {
	array = new vector<string>[size];
	size_of_table = size;
}

// Add item to hash table
void Hash_Table::addItem(string item) {
	int index = hash_function(item);
	(array + index)->push_back(item);
}

// Does item exist in the table?
bool Hash_Table::searchItem(string item) {
	int index = hash_function(item);
	vector<string> test = *(array + index);
	for (int i = 0; i < test.size(); i++) {
		if (test[i] == item)
			return true;
	}
	return false;
}

// Retrieve index in hash table of given item
int Hash_Table::hash(string item) {
	return hash_function(item);
}

// Retrieve size used to construct hash table
int Hash_Table::getSize() {
	return size_of_table;
}