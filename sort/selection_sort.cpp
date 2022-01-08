#include <iostream>

using std::cout;
using std::endl;

void selection_sort(int arr[], int size) {
	int i, j, tmp, min;

	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	selection_sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
	cout << endl;

	return 0;
}