#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 집의 수
int n;
// 각 색으로 칠할 때 는 비용
std::vector<std::array<int, 3>> cost;
// 전 집의 색에 따라 최소로 칠하는 비용(3가지 경우)
std::array<std::array<int, 3>, 1001> dp;

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 집의 수 입력
    cin >> n;

    // 각 집을 색으로 칠할 때 드는 비용 입력
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cost.push_back({ a,b,c });
    }

    // 첫 번째 집을 각 색으로 칠할 때는 드는 비용 미리 입력
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    // 첫 번째 집의 칠하는 경우에 따라서 3가지로 구분
    // 다음 집을 칠할 때는 전 집의 색을 피해서 칠한다.
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    // 3가지 경우 중 최솟값 출력
    cout << std::min(dp[n - 1][0], std::min(dp[n - 1][1], dp[n - 1][2])) << '\n';

    return 0;
}