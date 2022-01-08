#include <iostream>

using std::cout;
using std::endl;

void insertion_sort(int arr[], int first, int last, int gap) {
	int i, j, key;

	for (i = first + gap; i <= last; i += gap) {
		key = arr[i];
		for (j = i - gap; j >= first; j -= gap) {
			if (arr[j] > key) {
				arr[j + gap] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + gap] = key;
	}
}

void shell_sort(int arr[], int size) {
	int gap = size;

	while ((gap /= 2) != 0) {
		if (gap % 2 == 0)
			gap += 1;
		for (int i = 0; i < gap; i++) {
			insertion_sort(arr, i, size - 1, gap);
		}
	}
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	shell_sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	return 0;
}