#include <iostream>
#include <string>

int change(int& a, int& b, int& cnt) {
	// b가 a보다 크다면 변환 불가
	if (a > b) {
		return -1;
	}
	// a와 b가 같다면 연산 횟수 반환
	if (a == b) {
		return cnt;
	}
	// 짝수면 2로 나눈다.
	if (b % 2 == 0) {
		b /= 2;
	}
	// 마지막 숫자가 1이면 1을 뗀다.
	else if (b % 10 == 1) {
		b /= 10;
	}
	// 둘다 아니라면 변환 불가
	else {
		return -1;
	}

	cnt++;

	// 변환 불가 판정이 나왔다면 불가
	if (change(a, b, cnt) == -1) {
		return -1;
	}

	return cnt;
}
int main() {
	int a, b, cnt = 1;
	std::cin >> a >> b;

	std::cout << change(a, b, cnt) << std::endl;

	return 0;
}