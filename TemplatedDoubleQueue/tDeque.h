#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;
template <typename T>
class Deque {
	//Class members
private:
	T * queue;
	int num_elements;
	int size_of_queue;
	//Resize array, double size
	void resize_bigger() {
		T * newArr;
		//double size 
		newArr = new T[size_of_queue * 2];
		//	Transfer elements
		for (int i = 0; i < size(); i++) {
			newArr[i] = queue[i];
		}
		//remove old array
		delete[]queue;
		queue = newArr;
		//update size of current queue
		size_of_queue *= 2;
	}
	//Resize array, half size, min = 8
	void resize_smaller() {
		T * newArr;
		//Divide size by 2, min = 8
		if (size_of_queue / 2 >= 8) {
			newArr = new T[size_of_queue / 2];
		}
		else {
			newArr = new T[8];
		}
		//	Transfer elements
		for (int i = 0; i < size(); i++) {
			newArr[i] = queue[i];
		}
		//remove old array
		delete[]queue;
		queue = newArr;
		//update size of current queue
		size_of_queue /= 2;
	}

public:
	//Constructor
	Deque() {
		//initialization to min size of 8, starting size of 0, max size of 8
		queue = new T[8];
		num_elements = 0;
		size_of_queue = 8;
	}

	//Deconstructor
	~Deque() {
		//delete array 
		delete[]queue;
	}

	//Add item to front
	void push_front(T item) {
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

	//Add item to back
	void push_back(T item) {
		//if at max size...
		if (num_elements == size_of_queue) {
			//increase array size
			resize_bigger();
		}
		//O(1) add to end
		*(queue + num_elements) = item;
		num_elements++;
	}

	//Remove + return item from front of queue
	T pop_front() {
		//if queue is empty..
		if (size() == 0)
			throw logic_error("Error: attempting to remove element from empty queue");
		//save element to be deleted
		T back = *(queue);
		//O(N) shift left
		for (int i = 0; i < size(); i++)
			*(queue + i) = *(queue + i + 1);
		T * temp = queue + num_elements - 1;
		temp = NULL;
		num_elements--;
		// check for min size constraint
		if (num_elements < size_of_queue / 4)
			resize_smaller();
		return back;
	}

	//Remove + return item from back of queue
	T pop_back() {
		//save element to be deleted
		T back = *(queue + num_elements - 1);
		//if queue is empty..
		if (size() == 0) {
			throw logic_error("Error: attempting to remove element from empty queue");
			back = 0;
		}
		//overwrite with null 
		T * temp = queue + num_elements - 1;
		temp = NULL;
		num_elements--;
		// check for min size constraint
		if (num_elements < size_of_queue / 4)
			resize_smaller();
		return back;
	}

	//Return queue size
	int size() {
		return num_elements;
	}

	//Is Empty?
	bool empty() {
		return (num_elements == 0);
	}

	//print elements
	string toStr() {
		stringstream ss;
		string space = "\n";
		//return string with all elements, one per line
		for (int i = 0; i < size(); i++) {
			ss << *(queue + i);
			ss << space;
		}
		return ss.str();
	}
};