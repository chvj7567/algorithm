#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 3 x n일때 가능한 타일의 수
std::array<int, 31> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 길이
    int n;

    // 길이 입력
    cin >> n;

    // 길이가 홀수 일때는 불가능하다.
    for (int i = 1; i <= n; i += 2) {
        dp[i] = 0;
    }

    // 0일때 타일로 안 채우는 방법 하나와
    // 2일때 3가지 방법이 있다.
    dp[0] = 1;
    dp[2] = 3;

    // 길이가 1이 늘어났다면 홀수이니 타일로 채울 수 없고,
    // 길이가 2가 늘어났다면 앞에서 말한 3가지 방법으로
    // 채울 수 있으니 * 3을 한다.
    // 길이가 3이 늘어났다면 똑같이 홀수이니 타일로 채울 수 없다.
    // 길이가 4부터는 가로 방향으로 2개를 이어붙인 형태로
    // 길이가 2인 방법과 겹치지 않는 방법이 두 가지가 있다.
    // --
    // |=| 중간에 =은 2 x 1 타일 두개를 눕혀놓은 형태다.
    // ----
    // |==| 이 형태로 4, 6, 8, 10 ...이 될 때마다 2가지씩 늘어난다.
    // 즉, 길이가 4이상일때 길이가 2씩 늘어날때마다 *2한 방법의 수를 더해준다.
    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}