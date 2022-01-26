#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 상담이 걸리는 일 수 와 비용
std::array<std::pair<int, int>, 16> cst = {};
// n일까지 일했을 때 얻는 최대 수익
std::array<int, 16> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 가능한 일의 수
    int n;

    // 가능한 일의 수 입력
    cin >> n;

    // 상담 일정 입력
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        cst[i] = { a, b };
    }
    
    for (int i = 1; i <= n; ++i) {
        // i날짜에 상담을 했을 경우
        int day = i + cst[i].first;
        // n일에 1일치 일을 한 경우도 있으므로 n + 1일까지
        if (day <= n + 1) {
            // 기존값과 i날짜에 한 상담 비용을 더했을때 최댓값
            dp[day] = std::max(dp[day], dp[i] + cst[i].second);
        }
        // n일째 받은 비용은 n일째에 1일치 일을 한 경우를 포함해서
        // n + 1일째 받은 비용과 비교 후 최댓값 저장
        dp[i + 1] = std::max(dp[i], dp[i + 1]);
    }

    cout << dp[n + 1] << '\n';

    return 0;
}