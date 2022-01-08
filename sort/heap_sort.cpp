#include <iostream>

using std::cout;
using std::endl;

inline void SWAP(int& x, int& y, int tmp = 0) {
	tmp = x; x = y; y = tmp;
};

void min_heap(int arr[], int n, int size) {
	int i = n;
	int left, right;

	while (i >= 0) {
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (right >= size) {
			if (arr[i] < arr[left]) SWAP(arr[i], arr[left]);
			i--;
			continue;
		}
		if (!(arr[i] > arr[left] && arr[i] > arr[right])) {
			if (arr[left] < arr[right]) {
				SWAP(arr[i], arr[right]);
			}
			else {
				SWAP(arr[i], arr[left]);
			}
		}
		i--;
	}
}

void max_heap(int arr[], int n, int size) {
	int i = n;
	int left, right;

	while (i >= 0) {
		left = 2 * i + 1;
		right = 2 * i + 2;

		if (right >= size) {
			if (arr[i] > arr[left]) SWAP(arr[i], arr[left]);
			i--;
			continue;
		}
		if (!(arr[i] < arr[left] && arr[i] < arr[right])) {
			if (arr[left] > arr[right]) {
				SWAP(arr[i], arr[right]);
			}
			else {
				SWAP(arr[i], arr[left]);
			}
		}
		i--;
	}
}

void heap(int arr[], int size, int num) {
	switch (num) {
	case 1:
		for (int i = size; i > 0; i--) {
			min_heap(arr, i / 2 - 1, i);
			SWAP(arr[0], arr[i - 1]);
		}
		break;
	case 2:
		for (int i = size; i > 0; i--) {
			max_heap(arr, i / 2 - 1, i);
			SWAP(arr[0], arr[i - 1]);
		}
		break;
	default:
		break;
	}
}

int main() {
	int arr[] = { 7,4,5,1,3,2,6,9,8 };

	int size = sizeof(arr) / sizeof(arr[0]);

	heap(arr, size, 1);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	heap(arr, size, 2);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	cout << endl;

	return 0;
}