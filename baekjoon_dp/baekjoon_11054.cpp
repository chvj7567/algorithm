#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 수열
std::array<int, 1001> seq = {};
// 증가하는 부분 수열
std::array<int, 1001> dp1 = {};
// 감소하는 부분 수열
std::array<int, 1001> dp2 = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 수열의 수
	int n;

	// 수열의 수 입력
	cin >> n;

	// 수열 입력
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
	}

	// 1로 초기화
	std::fill(dp1.begin(), dp1.end(), 1);
	std::fill(dp2.begin(), dp2.end(), 1);

	// 증가하는 부분 수열의 최대 길이(바이토닉 수열의 좌측 부분)
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (seq[j] < seq[i]) {
				dp1[i] = std::max(dp1[i], dp1[j] + 1);
			}
		}
	}

	// 감소하는 부분 수열의 최대 길이(바이토닉 수열의 우측 부분)
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j) {
			if (seq[j] < seq[i]) {
				dp2[i] = std::max(dp2[i], dp2[j] + 1);
			}
		}
	}

	// 기준이 되는 수는 2번 계산되었으므로 -1
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		answer = std::max(answer, dp1[i] + dp2[i] - 1);
	}

	cout << answer << '\n';

	return 0;
}