#include <string>
#include <iostream>
using namespace std;

class Deque {
	//Class members
private:
	string * queue;
	int num_elements;
	int size_of_queue;
	//Resize array, double size
	void resize_bigger();
	//Resize array, half size, min = 8
	void resize_smaller();

public:
	//Constructor
	Deque();

	//Deconstructor
	~Deque();

	//Add item to front
	void push_front(string item);

	//Add item to back
	void push_back(string item);

	//Remove + return item from front of queue
	string pop_front();

	//Remove + return item from back of queue
	string pop_back();

	//Return queue size
	int size();

	//Is Empty?
	bool empty();

	//print elements
	string toStr();
};