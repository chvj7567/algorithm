#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 각 수에 대해 1로 만드는 최소 연산 수
std::array<int, 1000001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정수
    int n;

    // 정수 n 입력
    cin >> n;

    // 수를 가장 빨리 줄이기 위해서는
    // 나누는게 중요한데 나누어 떨어질때의 경우와
    // 1을 뺐을 때 경우를 나누어 최솟값을 비교한다.
    // 3이 2보다 더 크게 줄일 수 있으므로 3으로
    // 먼저 나눌 수 있는지 검사한다.
    for (int i = 2; i <= n; ++i) {
        // 1을 뺐을 때 결과
        dp[i] = dp[i - 1] + 1;

        // 3으로 나누어 떨어진다면
        if (i % 3 == 0) {
            // 1을 뺐을 때와 3으로 나눴을 때 최솟값 
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
        // 2로 나누어 떨어진다면
        if (i % 2 == 0) {
            // 1을 뺐을 때와 2로 나눴을 때 최솟값
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}