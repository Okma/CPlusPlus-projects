#include "sDeque.h"

Deque::Deque() {
	//initialization to min size of 8, starting size of 0, max size of 8
	queue = new string[8];
	num_elements = 0;
	size_of_queue = 8;
}

Deque::~Deque() {
	//delete array 
	delete[]queue;
}

void Deque::resize_bigger() {
	string * newArr;
	//double size 
	newArr = new string[size_of_queue * 2];
	for (int i = 0; i < size(); i++) {
		newArr[i] = queue[i];
	}
	//remove old array
	delete[]queue;
	queue = newArr;
	//update size of current queue
	size_of_queue *= 2;
}
void Deque::resize_smaller() {
	string * newArr;
	//Divide size by 2, min of 8
	if (size_of_queue / 2 >= 8) {
		newArr = new string[size_of_queue / 2];
	}
	else {
		newArr = new string[8];
	}
	for (int i = 0; i < size(); i++) {
		newArr[i] = queue[i];
	}
	//remove old array
	delete[]queue;
	queue = newArr;
	//update size of current queue
	size_of_queue /= 2;
}

void Deque::push_front(string item) {
	//if at max size...
	if (num_elements == size_of_queue) {
		//increase array size
		resize_bigger();
	}
	//O(N) shift right
	for (int i = num_elements; i > 0; i--)
		*(queue + i) = *(queue + i - 1);
	*(queue) = item;
	num_elements++;
}

void Deque::push_back(string item) {
	//if at max size...
	if (num_elements == size_of_queue) {
		//increase array size
		resize_bigger();
	}
	//O(1) add to end
	*(queue + num_elements) = item;
	num_elements++;
}

string Deque::pop_front() {
	//if queue is empty..
	if (size() == 0) return 0;
	//save string to be deleted
	string back = *(queue);
	//O(N) shift left
	for (int i = 0; i < size(); i++)
		*(queue + i) = *(queue + i + 1);
	//overwrite with null string
	*(queue + num_elements - 1) = "";
	num_elements--;
	return back;
}

string Deque::pop_back() {
	//if queue is empty..
	if (size() == 0) return 0;
	//save string to be deleted
	string back = *(queue + num_elements - 1);
	//overwrite with null string
	*(queue + num_elements - 1) = "";
	num_elements--;
	if (num_elements < size_of_queue / 4)
		resize_smaller();
	return back;
}

int Deque::size() {
	return num_elements;
}

bool Deque::empty() {
	return (*queue).empty();
}

string Deque::toStr() {
	string output;
	//return string with all elements, one per line
	for (int i = 0; i < size(); i++) {
		output += *(queue + i);
		output += "\n";
	}
	return output;
}
