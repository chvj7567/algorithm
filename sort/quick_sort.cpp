#include <iostream>

using std::cout;
using std::endl;

#define SWAP(X, Y, T) ((T)=(X), (X)=(Y), (Y)=(T))

void quick_sort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}

	int i = left + 1, j = right, tmp;

	while (i <= j) {
		while (arr[i] <= arr[left] && i <= right) {
			i++;
		}
		while (arr[j] >= arr[left] && j >= left + 1) {
			j--;
		}
		if (i > j) {
			SWAP(arr[left], arr[j], tmp);
		}
		else {
			SWAP(arr[i], arr[j], tmp);
		}
	}

	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, 0, size - 1);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	return 0;
}