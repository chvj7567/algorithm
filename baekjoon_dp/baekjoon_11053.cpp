#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 수열의 수
int n;
// 수열
std::array<int, 1001> seq = {};
// n개의 수열이 가지는 가장 긴 증가하는 부분 수열의 수
std::array<int, 1001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 수열의 수 입력
    cin >> n;

    // 수열 입력
    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
    }

    // 각 수열의 증가하는 부분 수열은 자기 자신을 포함한다.
    std::fill(dp.begin(), dp.end(), 1);

    // 증가하는 부분 수열이기 위해서는
    // 자기 자신 전의 수들 중에 자기보다 작은 수가 존재한다.
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 1; --j) {
            if (seq[i] > seq[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        answer = std::max(dp[i], answer);
    }

    cout << answer << '\n';

    return 0;
}