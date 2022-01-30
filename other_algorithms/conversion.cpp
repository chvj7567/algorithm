#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string conversion(int num, int base) {
	std::string result;
	int remainder;

	if (num == 0) {
		return result;
	}

	result += conversion(num / base, base);
	remainder = num % base;

	if (remainder < 10) {
		result += (remainder + '0');
	}
	else {
		result += remainder - 10 + 'A';
	}

	return result;
}
int main() {
	int num, base;

	cin >> num >> base;

	std::string con = conversion(num, base);

	if (con == "") {
		cout << '0' << endl;
	}
	else {
		cout << con << endl;
	}

	return 0;
}