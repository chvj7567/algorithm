#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 동전의 종류
std::array<int, 101> coin = {};
// 동전의 최소 갯수
std::array<int, 100001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 동전의 종류와 목표 금액
    int n, k;

    // 동전의 종류와 목표 금액 입력
    cin >> n >> k;
    // 초기화
    std::fill(dp.begin(), dp.end(), 10001);

    // 각 동전의 가치를 입력 후
    // 각 동전의 금액일 때는 해당 동전만 있을 때가
    // 동전의 최소 갯수이다.
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
        dp[coin[i]] = 1;
    }

    // 내림차순으로 정렬
    std::sort(coin.begin(), coin.end(), std::greater<int>());

    // 목표 금액이 7이고 2, 5원이 있을 경우
    //   1 2 3 4 5 6 7
    // 2 0 1 0 2 0 3 1
    // 5 0 0 0 0 1 0 1
    // 위 처럼 표를 세우면 알 수 있는데 7원이 됐을 때
    // 7에서 최대 가치의 동전부터 빼본 후 양수라면
    // 7 - 5 = 2가되므로 2일때 최소 갯수인 1과
    // 동전을 5원 하나 뺀 것과 같으니 +1 한 가치와 차례대로
    // 비교하면 된다.
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > coin[j]) {
                dp[i] = std::min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    if (dp[k] == 10001) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[k] << '\n';
    }

    return 0;
}