#include <iostream>
#include <array>

using std::cin;
using std::cout;

std::array<int, 1001> dp = {};

int tile(int n) {
    // 직사각형의 길이가 1과 2일때는 고정
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }
    if (dp[n] != 0) {
        return dp[n];
    }

    // 길이가 1이 늘어날때는 1 x 2 타일을 붙이는 경우 한 가지
    // 길이가 2가 늘어날때는 2 x 1 타일을 붙이는 경우 한 가지와
    // 2 x 2 타일을 붙이는 경우 한 가지를 더해서 두 가지 경우
    // 1 x 2 타일을 붙이는 경우는 길이가 1늘어났을때 붙이는 경우에 포함
    return dp[n] = (tile(n - 2) * 2 + tile(n - 1)) % 10007;
}
int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 직사각형의 가로 길이
    int n;

    // 가로 길이 입력
    cin >> n;

    cout << tile(n) << '\n';

    return 0;
}