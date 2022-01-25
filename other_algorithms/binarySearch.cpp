#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int binarySearch(const std::vector<int>& v, int num) {
	int left = 0;
	int right = v.size() - 1;
	int mid = (left + right) / 2;

	while (left < right) {
		if (v[mid] == num) {
			return mid;
		}
		else if (v[mid] < num) {
			left = mid + 1;
		}
		else if (v[mid] > num) {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}

	return -1;
}

int binarySearch2(const std::vector<int>& v, int num, int left, int right) {
	int mid = (left + right) / 2;

	if (left == right) {
		return -1;
	}

	if (v[mid] == num) {
		return mid;
	}
	else if (v[mid] < num) {
		return binarySearch2(v, num, mid + 1, right);
	}
	else if (v[mid] > num) {
		return binarySearch2(v, num, left, mid - 1);
	}
}
int main() {
	std::vector<int> v{ 0,1,2,3,4,5,6,7,8,9 };

	cout << binarySearch(v, 8) << endl;
	cout << binarySearch(v, 11) << endl;
	cout << binarySearch2(v, 8, 0, 9) << endl;
	cout << binarySearch2(v, 11, 0, 9) << endl;

	return 0;
}