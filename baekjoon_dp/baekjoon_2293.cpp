#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 각 동전의 가치
std::array<int, 101> coin = {};
// 목표 금액일 때 가능한 동전의 경우의 수
std::array<int, 10001> dp = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 동전의 수와 목표 금액
	int n, k;

	// 동전의 수와 목표 금액 입력
	cin >> n >> k;

	// 각 동전의 가치 입력
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}
	
	// 목표 금액이 0원일때는 1가지 경우 뿐이다.
	dp[0] = 1;

	// 목표 금액의 경우의 수는 각 동전의 가치만큼
	// 뺀 경우의 수의 합이다.
	// 1, 2, 3원으로 5원을 만드는 경우의 수를 계산해보자.
	// 5원의 경우의 수는
	// 1원을 뺐을 때 1원과 4원
	// 2원을 뺐을 때 2원과 3원
	// 3원을 뺐을 때 3원과 2원
	// 이렇게 동전의 가치만큼 빼면(동전의 수가 아니기 때문에
	// 동전 1개 가치를 뺀다고 경우의 수는 변하지 않는다.)
	// 결국 동전 1개의 가치로 수렴된다.
	// 동전의 가치는 각각 다르므로 그 수를 더해주면
	// 최종 목표를 만드는 경우의 수가 된다.
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= k; ++j) {
			dp[j] += dp[j - coin[i]];
		}
	}
	
	cout << dp[k] << '\n';

	return 0;
}