#include <iostream>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

// 제곱수 항의 최소 개수
std::array<int, 100001> dp = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 자연수
	int n;

	// 자연수 입력
	cin >> n;

	// 초기화
	std::fill(dp.begin(), dp.end(), 2e9);

	// 0은 자연수의 제곱으로 나타낼 수 없다.
	dp[0] = 0;

	// 1 = 1^2
	// 2 = 1^2 + 1^2
	// 3 = 1^2 + 1^2 + 1^2
	// 4 = 2^2
	// 5 = 2^2 + 1^2
	// 6 = 2^2 + 1^2 + 1^2
	// 7 = 2^2 + 1^2 + 1^2 + 1^2
	// 8 = 2^2 + 2^2
	// 9 = 3^2
	// 10 = 3^2 + 1^2
	// 11 = 3^2 + 1^2 + 1^2
	// 12 = 2^2 + 2^2 + 2^2
	// 규칙을 보고 아래의 식을 대입해보면 된다.
	for (int i = 1; i <= n; ++i) {
		int tmp = std::sqrt(i);
		for (int j = 1; j <= tmp; ++j) {
			dp[i] = std::min(dp[i], dp[i - std::pow(j, 2)] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}