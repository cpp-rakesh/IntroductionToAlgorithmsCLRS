#include "RadixSort.h"
#include "CountingSort.h"
#include "QuickSortRandom.h"
#include "QuickSortHoare.h"
#include "QuickSortHoareInitial.h"
#include "Exercise8.2_4.h"
#include "Common.h"
#include <cstdio>

void test_quick_sort_random() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortRandom<int> sort;
	Common<int> common;
	common.PrintVector(V);
	//sort.SortAscending(V);
	sort.SortDescending(V);
	common.PrintVector(V);	
}

void test_quick_sort_hoare() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	//int A[] = {5, 3, 2, 6, 4, 1, 3, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortHoare<int> sort;
	Common<int> common;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);	
}

// This is the initial Hoare parition algorithm implementation
void test_quick_sort_hoare_initial() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	//int A[] = {5, 3, 2, 6, 4, 1, 3, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortHoareInitial<int> sort;
	Common<int> common;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);	
}

// This is the test for Counting sort
void test_counting_sort() {
	int A[] = {9, 8, 2, 3, 4, 5, 3, 4, 4, 2, 1, 3, 3, 5, 6, 7, 0, 0, 0, 1, 2, 3, 4, 5, 6, 9, 8, 8, 3, 2};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	CountingSort<int, 10> sort;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);
}

// This is the test for Radix Sort
void test_radix_sort() {
	int A[] = {981, 2831, 83, 18, 9, 183, 8482, 83, 123, 38, 8, 262, 3848, 12, 72, 73, 123, 848, 12, 84};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	RadixSort<int> sort;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);		
}

// This is the solution for Exercise 8.2-4 from Introduction to Algorithms
void test_exercise82_4() {
	int A[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	Exercise82_4<int, 5> numbers(V);
	int start = 1;
	int end = 5;
	printf("Numner of Elements between [%d] and [%d] range == [%d]\n", start, end, numbers.NumberOfElements(start, end));
}

int main() {
	//test_quick_sort_random();
	//test_quick_sort_hoare();
	//test_quick_sort_hoare_initial();

	//test_counting_sort();
	test_radix_sort();
	
	//test_exercise82_4();
	
	return 0;
}