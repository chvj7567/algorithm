#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// 최솟값과 최댓값 지정
void minMax(std::string str, int& min, int& max) {
	// 5나 6인 수를 5로 지정
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '5' || str[i] == '6') {
			str[i] = '5';
		}
	}
	// 최솟값
	min = stoi(str);

	// 5나 6인 수를 6으로 지정
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '5' || str[i] == '6') {
			str[i] = '6';
		}
	}
	// 최댓값
	max = stoi(str);
}

int main() {
	// 두 수
	int a, b;
	// a의 최솟값, b의 최솟값
	int min_a, min_b;
	// a의 최댓값, b의 최댓값
	int max_a, max_b;

	// 두 수 입력
	cin >> a >> b;

	// a와 b의 최솟값, 최댓값
	minMax(std::to_string(a), min_a, max_a);
	minMax(std::to_string(b), min_b, max_b);

	cout << min_a + min_b << " " << max_a + max_b << endl;

	return 0;
}