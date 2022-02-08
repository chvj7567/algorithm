#include <iostream>
#include <array>

using std::cin;
using std::cout;

std::array<long long, 1000001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // n번째
    int n;

    // n번째 입력
    cin >> n;

    // 0 ~ 9번째는 각 인덱스 번호가 곧 감솜하는 수이다.
    for (int i = 0; i < 10; ++i) {
        dp[i] = i;
    }

    // 0 1 2 3 4 5 6 7 8 9
    // 10 20 21 30 31 32 40 41 42 43...
    // 210 320 321 430 431 432 420 421 410...
    // 규칙을 보면 자릿 수가 늘어날 때마다 이전 자릿수의
    // 숫자들이 들어가는 걸 볼 수 있다.
    if (n >= 10) {
        int cnt = 10;
        for (int i = 1; i <= n; ++i) {
            // 이전 숫자보다 작은 숫자의 경우까지만 반복
            for (int j = 0; j < (dp[i] % 10); ++j) {
                dp[cnt++] = dp[i] * 10 + j;
            }
        }
    }

    // 최대 감소하는 수인 9876543210을 넘어가면 -1 출력
    if (n > 1022) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[n] << '\n';
    }

    return 0;
}