#include "BST.h"

using namespace std;

BST::Node::Node(int data) {
	this->data = data;
	left = 0;
	right = 0;
}

BST::BST(Node * r) {
	root = r;
}

void BST::add(int newData) {
	Node * newNode = new Node(newData);
	if (!root) {
		root = newNode;
	}
	else {
		Node * temp = root;
		while (temp->right != newNode || temp->left != newNode) {
			if (newData < temp->data) {
				if (temp->left != 0)
					temp = temp->left;
				else
					temp->left = newNode;
			}
			else {
				if (temp->right != 0)
					temp = temp->right;
				else
					temp->right = newNode;
			}
		}
	}
}

bool BST::search(int lookFor) {
	if (!root)
		return 0;
	Node * temp = root;
	if (lookFor < temp->data) {

	}
}