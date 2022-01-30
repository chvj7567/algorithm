#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n번째 자리에 각 숫자가 올때 가능한 오르막 수의 수
std::array<std::array<int, 11>, 1001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 자릿 수
    int n;

    // 자릿 수 입력
    cin >> n;

    // 0부터 9는 모두 오르막수이다.
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }

    // 0이면 0부터 9까지 올 수 있고,
    // 1이면 1부터 9까지 올 수 있다.
    // 즉, 이전 숫자가 0이면 이전의 0부터 9까지의
    // 경우의 수를 모두 더한 것과 같다.
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            long long sum = 0;
            for (int k = j; k < 10; ++k) {
                sum += dp[i - 1][k];
            }
            dp[i][j] = sum % 10007;
        }
    }

    long long answer = 0;
    for (int i : dp[n]) {
        answer += i;
    }

    cout << answer % 10007 << '\n';

    return 0;
}