#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// S의 범위는 unsigned int의 범위이다.
	unsigned int S, N = 1;

	// S 입력
	cin >> S;

	// 1부터 1씩 추가한 값을 더한 후
	// 그 값이 S를 넘어가면 그 남은 값
	// 자체가 마지막 숫자이며,
	// 마지막 값은 +1해서 비교한 값을
	// 뺀 N-1이다.
	while (S >= N) {
		S -= N;
		N++;
	}
	cout << N - 1 << endl;

	return 0;
}