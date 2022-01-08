#include <iostream>

using std::cout;
using std::endl;

void insertion_sort(int arr[], int size) {
	int i, j, key;

	for (i = 1; i < size; i++) {
		key = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = key;
	}
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	insertion_sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	return 0;
}