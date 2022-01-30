#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 수열
std::array<int, 1001> seq = {};
// 수를 기준으로 하는 합이 가장 큰 증가 부분 수열의 합
std::array<int, 1001> dp = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 수열의 수
	int n;

	// 수열의 수 입력
	cin >> n;

	// 수열 입력, dp 초기화(자기자신을 합에 포함)
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
		dp[i] = seq[i];
	}

	// 각 인덱스를 기준으로 증가 부분 수열 중
	// 합이 가장 큰 부분을 구한다.
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (seq[j] < seq[i]) {
				dp[i] = std::max(dp[i], dp[j] + seq[i]);
			}
		}
		answer = std::max(answer, dp[i]);
	}

	cout << answer << '\n';

	return 0;
}