
#include "Sorting.h"



void make_heap(int *a, const int& length);
void reheapify_down(int *a, const int& length);
inline int parent(int k) { return (k - 1) / 2; }
inline int left_child(int k) { return (2 * k) + 1; }
inline int right_child(int k) { return (2 * k) + 2; }

void partition(int *a, const int& length, int& pivot);
void get_pivot(int *a, const int& length);


void selection_sort(int *a, const int& length) {

	int min_index;

	for (int i = 0; i < length -1; ++i) {
		min_index = i;
		for (int j = i + 1; j < length; ++j) {
			if (a[j] < a[min_index])
				min_index = j;
		}
		if (min_index != i) {
			swap_array(a, i, min_index);
		}
	}
}

void swap_array(int *a, const int& index_one, const int& index_two) {

	int temp = a[index_one];
	a[index_one] = a[index_two];
	a[index_two] = temp;
}

void bubble_sort(int *a, const int& length) {

	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < length - 1; ++i) {
			if (a[i+1] < a[i]) {
				swap_array(a, i, i + 1);
				swapped = true;
			}
		}
	} while (swapped);
}

void insertion_sort(int*a, const int& length) {

	int j;
	for (int i = 1; i < length; ++i) {

		j = i;
		while (j > 0 && a[j] < a[j-1]) {

			swap_array(a, j, j - 1);
			j = j - 1;
		}
	}
}

void merge_sort(int *a, const int& length) {

	int n1; // Length of first smaller array
	int n2; // Length of second smaller array

	if (length > 1) {

		n1 = length / 2;
		n2 = length - n1;

		merge_sort(a, n1);
		merge_sort(a + n1, n2);

		//Merge the sub-arrays
		int *temp = new int[length];
		int copied = 0;
		int copied1 = 0;
		int copied2 = 0;

		while ((copied1 < n1) && (copied2 < n2)) {
			if (a[copied1] < (a + n1)[copied2]) {
				temp[copied] = a[copied1];
				++copied;
				++copied1;
			}
			else {
				temp[copied] = (a + n1)[copied2];
				++copied;
				++copied2;
			}
		}

		while (copied1 < n1) {
			temp[copied] = a[copied1];
			++copied;
			++copied1;
		}

		while (copied2 < n2) {
			temp[copied] = (a + n1)[copied2];
			++copied;
			++copied2;
		}

		for (int i = 0; i < length; ++i)
			a[i] = temp[i];
		delete[] temp;
	}
}

void quick_sort(int *a, const int& length) {

	int pivot_index;
	int n1;
	int n2;

	if (length > 1) {
		partition(a, length, pivot_index);

		n1 = pivot_index;
		n2 = length - n1 - 1;

		quick_sort(a, n1);
		quick_sort((a + pivot_index + 1), n2);
	}
}


void partition(int *a, const int& length, int& pivot_index) {

	int too_big_index = 1;
	int too_small_index = length - 1;
	get_pivot(a, length);
	int pivot = a[0];
	//int pivot = a[0];

	while (too_big_index <= too_small_index) {
		while (too_big_index < length && a[too_big_index] <= pivot) {
			++too_big_index;
		}
		while (a[too_small_index] > pivot) {
			--too_small_index;
		}
		if (too_big_index < too_small_index)
			swap_array(a, too_big_index, too_small_index);
	}

	pivot_index = too_small_index;

	a[0] = a[pivot_index];
	a[pivot_index] = pivot;
}

//The pivot for the quicksort algorithm will be the median of the first, last
//and middle array elements
void get_pivot(int *a, const int& length) {

	int mid_index = length / 2;
	int last_index = length - 1;

	if (a[0] < a[mid_index])
	{
		if (a[mid_index] < a[last_index]) {
			swap_array(a, 0, mid_index);
		}
	}
	else
	{
		if (a[mid_index] >= a[last_index]) {
			swap_array(a, 0, mid_index);
		}
	}
	swap_array(a, 0, last_index);
}

void heap_sort(int *a, const int& length) {

	int unsorted;

	make_heap(a, length);
	unsorted = length;

	while (unsorted > 1) {

		--unsorted;
		swap_array(a,0, unsorted);
		reheapify_down(a, unsorted);
	}

}

void make_heap(int *a, const int& length) {

	int k;
	int parent_index;
	for (int i = 1; i < length; ++i) {

		k = i;
		parent_index = parent(k);
		while (k != 0 && a[k] > a[parent_index]) {
			swap_array(a, k, parent_index);
			k = parent_index;
			parent_index = parent(k);
		}
	}
}

void reheapify_down(int *a, const int& length) {

	int current_index;
	int big_child_index;
	bool is_heap;
	int left_child_index;
	int right_child_index;

	current_index = 0;
	is_heap = false;
	left_child_index = left_child(current_index);
	right_child_index = right_child(current_index);

	while ((!is_heap) && ((length) > left_child_index)) {

		if (length <= right_child_index) {
			big_child_index = left_child_index;
		}
		else {
			if (a[left_child_index] < a[right_child_index])
				big_child_index = right_child_index;
			else
				big_child_index = left_child_index;
		}

		if (a[current_index] < a[big_child_index]) {
			swap_array(a, current_index, big_child_index);
			current_index = big_child_index;
		}
		else
			is_heap = true;

		left_child_index = left_child(current_index);
		right_child_index = right_child(current_index);
	}
}