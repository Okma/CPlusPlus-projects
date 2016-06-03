Concurrency Demo using Merge Sort
==================================
Purpose
----------
- Demonstrate the efficiency of multithreading with a comparison sort of N items (provided by the user).
- Runs 8 tests on X threads (determined by the host's computer).

Procedure
----------
1. Clock time.
2. Run sorting algorithm.
3. Clock time difference immediately after call finishes.
4. Output execution time.

Files Included
--------------
* README.txt
* mergesort.cpp
* Results.docx
* Makefile

Features
--------
* Single Thread Unstable Sort Method (std::sort)
* Single Thread Stable Sort Method (std::stable_sort)
* Single Thread Merge Sort (recursive method, out-of-place; r_merge_sort)
* Single Thread Merge Sort (non-recursive method, in-place; merge_sort)
* Multi-Thread Unstable Sort Method (std::sort)
* Multi-Thread Stable Sort Method (std::stable_sort)
* Multi-Thread Merge Sort (recursive method, out-of-place; r_merge_sort)
* Multi-Thread Merge Sort (non-recursive method, in-place; merge_sort)
* Thread Counting on per system basis (scaling)
* Time comparisons between methods

Installation
------------
* Run the given Makefile with a simple 'make' command OR
* Run the file in a suitable coding environment.

Support
---------
If you are having issues, please let me know.
You can reach me at c.amko@ufl.edu.