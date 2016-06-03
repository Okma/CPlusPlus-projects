#ifndef _BST_H
#define _BST_H
class BST {
private:
	class Node {
	public:
		int data;
		Node * left;
		Node * right;
		Node(int data);
	};
	Node * root;
public:
	BST(Node * r);
	void add(int newData);
	void remove(int lookFor);
	bool search(int data);
	int min();
	int max();
};
#endif