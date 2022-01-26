#include <iostream>
#include <array>

using std::cin;
using std::cout;
// 각 카드 팩의 가격
std::array<int, 1001> card = {};
// n개의 카드를 살때 최대 가격
std::array<int, 1001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 구매할 카드 수
    int n;

    // 구매할 카드 수 입력
    cin >> n;

    // 카드팩 가격 입력
    for (int i = 1; i <= n; ++i) {
        cin >> card[i];
    }

    // 1개를 살때는 1개짜리 팩만 구매 가능
    dp[1] = card[1];

    // dp의 인덱스 값과 card 팩의 인덱스 값이
    // 구하려는 dp의 인덱스 값이 된다는 규칙을 아래를 보면 알 수 있다.
    // 그것을 원래 본인의 값과 비교하여 max 값을 dp에 설정해준다.
    // dp[2] = max(dp[1] + card[1], dp[0] + card[2])
    // dp[3] = max(dp[2] + card[1], dp[1] + card[2], dp[0], card[3])
    // dp[4] = max(dp[3] + card[1], dp[2] + card[2], dp[1] + card[3], dp[0] + card[4])
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = std::max(dp[i], dp[i - j] + card[j]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}