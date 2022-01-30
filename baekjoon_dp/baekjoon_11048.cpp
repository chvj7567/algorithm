#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 해당 좌표에 도착할 시 얻을 수 있는 최대 갯수
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 미로의 세로, 가로 길이
    int n, m;

    // 미로의 세로, 가로 길이 입력
    cin >> n >> m;

    // 미로의 사탕 갯수 입력
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> dp[y][x];
        }
    }

    // 윗줄로 갈 때 얻을 수 있는 사탕의 갯수
    for (int y = 1; y <= n; ++y) {
        dp[y][1] += dp[y - 1][1];
    }

    // 좌측으로 갈 때 얻을 수 있는 사탕의 갯수
    for (int x = 1; x <= m; ++x) {
        dp[1][x] += dp[1][x - 1];
    }

    // 갈 수 있는 3가지 방법 중 얻을 수 있는 최대 사탕 갯수를 자기 자신과 더한다.
    for (int y = 2; y <= n; ++y) {
        for (int x = 2; x <= m; ++x) {
            dp[y][x] += std::max(dp[y - 1][x - 1], std::max(dp[y - 1][x], dp[y][x - 1]));
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}