#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n번째 자릿 수일때 마지막에 각 숫자가 올때 가능한 이친수의 수
std::array<std::array<long long, 91>, 91> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    // 한 자릿 수일때는 1밖에 오지 못함
    dp[1][0] = 0;
    dp[1][1] = 1;

    // 전 숫자가 0일때는 0또는 1
    // 전 숫자가 1일때는 1이 올 수 밖에 없다.
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1] << '\n';

    return 0;
}