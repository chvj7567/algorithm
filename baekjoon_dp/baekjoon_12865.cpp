#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 각 물건의 무게와 가치
std::array<std::array<int, 2>, 101> p = {};
// 각 무게만큼 버틸 때 얻을 수 있는 최대 가치
std::array<std::array<int, 100001>, 101> dp = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 물품의 수와 배낭이 버티는 무게
	int n, k;

	// 물품의 수와 배낭이 버티는 무게 입력
	cin >> n >> k;

	// 각 물건의 무게와 가치 입력
	for (int i = 1; i <= n; ++i) {
		cin >> p[i][0] >> p[i][1];
	}

	// 각 물건을 넣을 경우와 넣지 않을 경우로 나뉜다.
	// 각 물건을 넣을 때는 가방이 버티는 무게가 넘지않는 선에서
	// 계산하되, 각 물건을 넣지않고 다른 걸 넣었을 때와 비교 후
	// 최댓값을 저장한다.
	for (int i = 1; i <= n; ++i) {
		for (int j = k; j >= 1; --j) {
			if (j - p[i][0] >= 0) {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - p[i][0]] + p[i][1]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}