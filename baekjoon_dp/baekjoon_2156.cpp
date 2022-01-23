#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 잔의 수
int n;
// 포도주의 양
std::array<int, 10001> wine = {};
// n개의 포도주가 있을 때 마실 수 있는 최대 양
std::array<int, 10001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 잔의 수 입력
    cin >> n;

    // 포도주의 양 입력
    for (int i = 1; i <= n; ++i) {
        cin >> wine[i];
    }

    // 첫 번째, 두 번째 포도주의 최댓값 미리 입력
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // n개의 포도주를 최대로 마시는 경우의 수는
    // (*은 마시는 경우, 0은 마시지 않는 경우)
    // *0**, *0* 형태의 n번째 포도주를 마시는 경우와
    // *0 형태의 n번째 포도주를 마시지 않는 경우가 있다.
    for (int i = 3; i <= n; ++i) {
        dp[i] = std::max(dp[i - 2] + wine[i], std::max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1]));
    }

    cout << dp[n] << '\n';

    return 0;
}