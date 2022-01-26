#include <iostream>
#include <array>
#include <vector>
#include <string>

using std::cin;
using std::cout;

// 두 문자열
std::string s1, s2;
// 각 문자열의 길이에 따른 최대 LCS 수
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 두 문자열 입력
    cin >> s1 >> s2;

    // 끝 문자열을 기준으로 같은 경우와 다른 경우로 나뉜다.
    // 같은 경우 전의 LCS보다 1개를 늘려주면 되고,
    // 다르다면 인덱스를 다음 인덱스로 넘겨주어야 하는데
    // 두 가지 경우를 비교해서 max 값을 넣어준다.
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';

    return 0;
}