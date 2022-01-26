#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 길이가 n일때 가능한 경우의 수
std::array<long long, 1000001> dp = {};

// 타일의 경우의 수를 보면
// dp[1] = 1
// dp[2] = 11, 00
// dp[3] = 111, 100, 001
// dp[4] = 1111, 1100, 1001, 0011, 0000
// 이런 규칙들로 피보나치 수열처럼
// 늘어나는 것을 확인할 수 있다.
long long tile(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    return dp[n] = (tile(n - 2) + tile(n - 1)) % 15746;
}

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 길이
    int n;

    // 길이 입력
    cin >> n;

    cout << tile(n) << '\n';

    return 0;
}