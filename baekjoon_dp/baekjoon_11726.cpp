#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 각 길이에 대해 타일을 채울 수 있는 경우의 수
std::array<int, 1001> dp = {};

int tile(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    // 타일 경우의 수는 길이가 1이 늘어날 때 세우는 한 가지 경우와
    // 길이가 2가 늘어나는 경우는 길이가 1일때 세우는 경우에
    // 한 가지가 포함되므로 눕히는 경우 한 가지 경우가 있다.
    return dp[n] = (tile(n - 2) + tile(n - 1)) % 10007;
}
int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정수
    int n;

    // 정수 입력
    cin >> n;

    cout << tile(n) << '\n';

    return 0;
}