#include <thread>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

// Merge for Recursive Merge Sort
template <typename T>
void merge(vector<T>& vec, vector<T>& vec1, vector<T>& vec2) {

	vec.clear();

	int i, j, k;
	for (i = 0, j = 0, k = 0; i < vec1.size() && j < vec2.size(); k++) {
		// If left side <= right side, add left side item to main vector
		if (vec1.at(i) <= vec2.at(j)){
			vec.push_back(vec1.at(i));
			i++;
		}
		// If left side > rigt side, add right side item to main vector
		else if (vec1.at(i) > vec2.at(j)) {
			vec.push_back(vec2.at(j));
			j++;
		}
		k++;
	}
	// Left side -> Main Vector
	while (i < vec1.size()) {
		vec.push_back(vec1.at(i));
		i++;
	}
	// Right side -> Main Vector
	while (j < vec2.size()) {
		vec.push_back(vec2.at(j));
		j++;
	}
}

// Recursive Merge Sort
template <typename T>
void r_merge_sort(vector<T>& vec, int start, int end) {
	if (1 < end - start) {
		int mid = start + (end - start) / 2;

		// vec1 = left half; begin to mid
		vector<T> vec1(vec.begin() + start, vec.begin() + mid);
		r_merge_sort(vec1, 0, vec1.size());

		// vec2 = right half; mid to end
		vector<T> vec2(vec.begin() + mid + 1, vec.begin() + end);
		r_merge_sort(vec2, 0, vec2.size());
		merge(vec, vec1, vec2);
	}
}

// Bottom-up, Non-Recursive Merge Sort
template <typename T>
void merge_sort(vector<T>& vec, int start, int end) {
	int m = 1 + start;
	while (m < end){
		int i = 0;
		while (i < end - m) {
			inplace_merge(vec.begin() + i, vec.begin() + i + m, vec.begin() + min<int>(i + 2 * m - 1, end - 1));
			i += 2 * m;
		}
		m *= 2;
	}
}

// Stable Sort Method (std::stable_sort)
template <typename T>
void stableSort(vector<T> vec, int lower, int upper)
{
	stable_sort(vec.begin() + lower, vec.begin() + upper);
}

// Print method, if desired.
template <typename T>
void print(vector<T> vec) {
	for(T iter : vec) {
		cout << iter << " ";
	}
	cout << endl;
}

// Unstable Sort Method (std::sort)
template <typename T>
void regSort(vector<T> vec) {
	sort(vec.begin(), vec.end());
}

int main() {

	// Dummy variable for pausing to observe output.
	int a;

	// Query how many threads can be supported by this computer.
	unsigned int NUM_THREADS = std::thread::hardware_concurrency(); 

	// Initialize the quantity of items to test.
	int numItems = 10;

	// User input for number of test items.
	cout << "Enter the number of items to test: ";
	cin >> numItems;

	// Initialize storage vector.
	vector<int> ints;

	// Create a vector with numItems random elements.
	for(int i = 0; i < numItems; i++)
		ints.push_back(rand() % (int)(100000 + 1));
	
	// Single Thread Unstable Sort (std::sort)
	double t = clock();
	regSort(ints);
	t = clock() - t;
	cout << "Time using std::sort: " << (double)(t / CLOCKS_PER_SEC) << " seconds."<< endl;
	
	// Single Thread Stable Sort (std::stable_sort)
	t = clock();
	stableSort(ints, 0, ints.size());
	t = clock() - t;
	cout << "Time using one-thread stable sort: " << (double)(t / CLOCKS_PER_SEC) << " seconds." << endl;
	
	// Single Thread Recursive Merge Sort (r_merge_sort)
	t = clock();
	r_merge_sort(ints, 0, ints.size());
	t = clock() - t;
	cout << "Time using one-thread recursive merge sort: " << (double)(t / CLOCKS_PER_SEC) << " seconds." << endl;

	// Single Thread Non-Recursive Merge Sort (merge_sort) 
	t = clock();
	merge_sort(ints, 0, ints.size());
	t = clock() - t;
	cout << "Time using one-thread non-recursive merge sort: " << (double)(t / CLOCKS_PER_SEC) << " seconds." << endl;

	// Output number of supported threads by system.
	cout << "Number of supported threads: " << NUM_THREADS << endl;
	
	// Catch multithreading support failure.
	if(NUM_THREADS < 2) {
		cout << "Number of threads supported is less than can be used for multithreading." << endl;
		return 0;
	}

	// Initialize vector of threads to run concurrently.
	vector<thread> threads;

	// Divide number of section items equally per thread.
	int ItemsPerThread = ints.size() / NUM_THREADS;

	// Multi-Thread Stable Sort Method (std::stable_sort)
	t = clock();
	for (int i = 0; i < NUM_THREADS; i++) {
		threads.push_back(thread(&stableSort<int>, ref(ints), i * ItemsPerThread, (i + 1) * ItemsPerThread));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	t = clock() - t;
	threads.clear();
	cout << "Time using multi-threaded stable sort on " << NUM_THREADS << " threads: " <<(double)(t / CLOCKS_PER_SEC) << " seconds." << endl;

	// Multi-Thread Recursive Merge Sort (r_merge_sort)
	t = clock();
	for (int i = 0; i < NUM_THREADS; i++) {
		threads.push_back(thread(&r_merge_sort<int>, ref(ints), i * ItemsPerThread, (i + 1) * ItemsPerThread));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	t = clock() - t;
	threads.clear();
	cout << "Time using multi-threaded recursive merge sort on " << NUM_THREADS << " threads: " << (double)(t / CLOCKS_PER_SEC) << " seconds." << endl;

	// Multi-Thread Non-Recursive Merge Sort (merge_sort) 
	t = clock();
	for (int i = 0; i < NUM_THREADS; i++) {
		threads.push_back(thread(&merge_sort<int>, ref(ints), i * ItemsPerThread, (i + 1) * ItemsPerThread));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	t = clock() - t;
	threads.clear();
	cout << "Time using multi-threaded non-recursive merge sort on " << NUM_THREADS << " threads: " << (double)(t / CLOCKS_PER_SEC) << " seconds." << endl;

	cin >> a;
	
	
	return 0;
}