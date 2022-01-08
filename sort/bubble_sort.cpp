#include <iostream>

using std::cout;
using std::endl;

void bubble_sort(int arr[], int size) {
	int i, j, tmp;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	return 0;
}