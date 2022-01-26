#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n번째 자릿 수의 마지막에 각 숫자가 올 때 가능한 계단수의 수
std::array<std::array<int, 11>, 101> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 자릿 수
    int n;

    // 자릿 수 입력
    cin >> n;

    // 한 자릿 수 일때 미리 입력
    for (int i = 1; i < 10; ++i) {
        dp[1][i] = 1;
    }

    // 두 자릿 수부터 계산
    for (int i = 2; i <= n; ++i) {
        // 전 숫자가 0일때는 다음 숫자가 1,
        // 전 숫자가 9일때는 다음 숫자가 8
        // 밖에 오지 못한다.
        dp[i][0] = (dp[i - 1][1]) % 1000000000;
        dp[i][9] = (dp[i - 1][8]) % 1000000000;
        // 전 숫자가 2 ~ 8일때는 -1한 숫자와 +1한 숫자가 올 수 있다.
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    int answer = 0;
    for (int i : dp[n]) {
        answer += i;
        answer %= 1000000000;
    }

    cout << answer << '\n';

    return 0;
}