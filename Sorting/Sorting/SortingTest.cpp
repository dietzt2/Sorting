#include <cstdlib>
#include <iostream>
#include <random> //Not best RNG, but good enough to test the algorithms
#include "Sorting.h"
using namespace std;

void display_array(int *a, const int& length);
//Generates an array of length 'length' of random numbers
void generate_array(int *a, const int& length);

int main() {

	int dummy_var;
	const int a_length = 100000;
	int a[a_length];
	generate_array(a, a_length);
	//int a[a_length] = { 1,4,5,2,2,7,12,0,2, 8 };
	//int a[a_length] = { 1,4,5,2,2,7,1,0 };

	cout << "Before sort: " << endl;
	//display_array(a, a_length);

	heap_sort(a, a_length);

	// To delay the printing to see how fast the search is
	cout << "Enter a value to see the sorted results: ";
	cin >> dummy_var;

	cout << "After sort: " << endl;
	display_array(a, a_length);

	return EXIT_SUCCESS;
}

void display_array(int *a, const int& length) {

	for (int i = 0; i < length; ++i) {

		cout << i << ": " << a[i] << endl;
	}
}

void generate_array(int *a, const int& length) {

	for (int i = 0; i < length; ++i) {
		a[i] = rand();
	}
}