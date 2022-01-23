#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 수열의 수와 정답
int n, answer = -2e9;
// 수열
std::array<int, 100001> seq = {};
// n개의 수열의 연속된 값의 합의 최댓값
std::array<int, 100001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 수열의 수 입력
    cin >> n;

    // 수열 입력
    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
    }

    // 첫번째 수열 미리 입력
    dp[1] = seq[1];

    // 연속된 수의 합 중 최댓값을 구하기 위해서는
    // 이전 값들의 합이 음수가 아니거나
    // 해당 번째의 수를 더했을 때 음수가 되지 않을 때이다.
    // 두 경우가 아닐 때는 해당 번째 수를 더해주고
    // 두 경우에 포함될 때는 해당 번째 수를 시작으로 새로 더한다.
    int answer = -2e9;
    for (int i = 2; i <= n; ++i) {
        if (!(dp[i - 1] < 0 || dp[i - 1] + seq[i] < 0)) {
            dp[i] = dp[i - 1] + seq[i];
        }
        else {
            dp[i] = seq[i];
        }

        answer = std::max(answer, dp[i]);
    }

    // 첫 번째 수만 있는 경우와 비교를 하지 못했으므로 비교한다.
    answer = std::max(answer, dp[1]);

    cout << answer << '\n';

    return 0;
}