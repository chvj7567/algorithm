#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 서쪽 다리 수와 동쪽 다리 수가 주어질 때 가능한 다리 수
std::array<std::array<int, 31>, 31> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정답
    std::vector<int> answer;
    // 테스트 케이스 수와
    // 서쪽, 동쪽 사이트 수
    int test_case, n, m;

    // 테스트 케이스 수 입력
    cin >> test_case;

    while (test_case > 0) {
        // 서쪽, 동쪽 사이트 수 입력
        cin >> n >> m;

        // 서쪽 사이트 수가 1개 일때 가능한 다리 수는
        // 동쪽 사이트 수와 같다.
        // 서쪽, 동쪽 사이트 수가 같을때 가능한 다리수는 1개이다.
        for (int i = 1; i <= m; ++i) {
            dp[1][i] = i;
            dp[i][i] = 1;
        }

        // 표를 그려보면 알 수 있다.
        // (열-서쪽 사이트 수)
        // (행-동쪽 사이트 수)
        //   1 2 3 4
        //  |-------
        // 1|1 x x x 
        // 2|2 1 x x
        // 3|3 3 1 x
        // 4|4 6 4 1
        // 미리 지정된 수를 제외한 경우의 수를 보면
        // 행을 보면 이전 행의 두 가지의 합과 같다.
        // i가 열 j가 행
        for (int i = 2; i <= n; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }

        answer.push_back(dp[n][m]);

        --test_case;
    }

    for (int i : answer) {
        cout << i << '\n';
    }

    return 0;
}