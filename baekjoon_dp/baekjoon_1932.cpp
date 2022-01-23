#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 삼각형의 크기
int n;
// 삼각형의 상태
std::array<std::array<int, 501>, 501> tri = {};
// 다음 층을 갈때 가질 수 있는 최대 합
std::array<std::array<int, 501>, 501> dp = {};

int maxValue(int y, int x) {
    // 마지막 층일 경우는 자기 자신을 반환
    if (y == n - 1) {
        return tri[y][x];
    }

    if (dp[y][x] != 0) {
        return dp[y][x];
    }

    // 해당 층의 값과 다음 층을 갈때 최댓값을 합산
    return dp[y][x] = tri[y][x] + std::max(maxValue(y + 1, x), maxValue(y + 1, x + 1));
}
int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 삼각형의 크기 입력
    cin >> n;

    // 삼각형의 상태 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> tri[i][j];
        }
    }

    cout << maxValue(0, 0) << '\n';

    return 0;
}