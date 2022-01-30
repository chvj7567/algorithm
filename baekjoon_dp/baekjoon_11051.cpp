#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n개의 수 중 k개의 수를 뽑는 방법의 수
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 자연수와 정수
	int n, k;

	// 자연수와 정수 입력
	cin >> n >> k;

	// k가 1일때 뽑는 방법의 수는 n과 동일
	// k가 0이거나 n과 k가 같을 때 뽑는 방법의 수는 1
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = i;
		dp[0][i] = dp[i][i] = 1;
	}

	// 표를 그려보면 알 수 있다.
	// (열-k 정수)
	// (행-n 자연수)
	//   1 2 3 4
	//  |-------
	// 1|1 x x x 
	// 2|2 1 x x
	// 3|3 3 1 x
	// 4|4 6 4 1
	// 미리 지정된 수를 제외한 경우의 수를 보면
	// 행을 보면 이전 행의 두 가지의 합과 같다.
	// i가 열 j가 행
	for (int i = 2; i <= k; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[k][n] << '\n';

	return 0;
}