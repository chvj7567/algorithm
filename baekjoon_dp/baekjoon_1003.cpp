#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 각 수에 대해 피보나치 연산 시 0과 1을 호출하는 수
std::array<std::pair<int, int>, 41> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 숫자와 테스트 케이스 수
    int n, test_case;
    // 각 숫자를 담는 배열
    std::vector<int> number;

    // 테스트 케이스 수 입력
    cin >> test_case;

    while (test_case > 0) {
        cin >> n;

        number.push_back(n);

        // 0과 1일때 0과 1이 출력되는 수 미리 입력
        dp[0] = { 1,0 };
        dp[1] = { 0,1 };

        // 피보나치의 return값을 보면 답을 알 수 있다.
        for (int i = 2; i <= n; ++i) {
            dp[i] = { dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second };
        }
        --test_case;
    }

    for (int i : number) {
        cout << dp[i].first << " " << dp[i].second << '\n';
    }

    return 0;
}