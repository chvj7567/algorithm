#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 각 스티커의 점수
std::array<std::array<int, 2>, 100001> st = {};
// 각 스티커를 선택했을 경우 점수
std::array<std::array<int, 2>, 100001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정답
    std::vector<int> answer;
    // 테스트 케이스 수와 스티커 열의 수
    int test_case, n;

    // 테스트 케이스 수
    cin >> test_case;

    while (test_case > 0) {
        // 스티커 열의 수 입력
        cin >> n;

        // 각 스티커의 점수 입력
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> st[j][i];
            }
        }

        // 인덱스를 0부터 시작하여 0이 1열로 보면 된다.
        // dp의 인덱스 번호를 선택했을 경우의 점수이다.
        // 2열까지의 값을 미리 적어준다.
        dp[0][0] = st[0][0];
        dp[0][1] = st[0][1];
        dp[1][0] = dp[0][1] + st[1][0];
        dp[1][1] = dp[0][0] + st[1][1];

        // 3열 이상부터 경우의 수는 4가지다
        // x O x  0 x 0  x x 0  0 x x
        // 0 x 0, x 0 x, 0 x x, x x 0
        // 위 경우를 비교해주면 된다.
        for (int i = 2; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][1], dp[i - 2][1]) + st[i][0];
            dp[i][1] = std::max(dp[i - 1][0], dp[i - 2][0]) + st[i][1];
        }

        answer.push_back(std::max(dp[n - 1][0], dp[n - 1][1]));

        --test_case;
    }

    for (int i : answer) {
        cout << i << '\n';
    }

    return 0;
}