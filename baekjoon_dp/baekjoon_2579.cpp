#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 계단의 수
int n;
// 각 계단의 점수
std::array<int, 301> score = {};
// 각 계단에 오를 시 얻을 수 있는 최고 점수
std::array<int, 301> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 계단의 수 입력
    cin >> n;

    // 각 계단의 점수 입력
    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    // 첫 번째, 두 번째 계단의 점수 미리 입력
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];

    // 각 계단의 마지막은 꼭 점수를 얻어야 한다.
    // n번째 계단을 오르는 경우는(*이 밟는 계단, 0이 밟지 않는 계단)
    // *0** 과 **0*의 2가지 경우가 있다.
    for (int i = 3; i <= n; ++i) {
        dp[i] = std::max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}