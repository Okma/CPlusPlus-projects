#include "hash_table.h"
#include <cstdio>
#include <iostream>

int main () {
	Hash_Table * ht = new Hash_Table();
	int op, index;
	char input [80];
	scanf("%d %d", &op, &index);
	if( op != 1 ) {
	cout << "error: first input not 1" << endl;
		return 1;
	}
	while (2 == scanf("%d %s", &op, &input)) {
		switch( op ) {
			case 0:
			return 1;			
			break;
			case 1:
			ht->addItem( input );
			break;
			case 2:
			if(ht->searchItem( input))
				cout << "YES" << endl;
			else {
				cout << "NO" << endl;
			}
			break;
			default:
			cout << "error: input not 0-2." << endl;
			break;
		}
	
	}
	
	
	return 0;
}