#include <iostream>
#include <vector>
#include <string>
#include <regex>

using std::cin;
using std::cout;

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 테스트 케이스 수
    int test_case;
    // 전파 저장
    std::string str;

    // 테스트 케이스 수 입력
    cin >> test_case;

    // 정규표현식으로 규칙 표현
    std::regex re("(100+1+|01)+");
    // 정답
    std::vector<std::string> answer;

    while (test_case > 0) {
        // 전파 입력
        cin >> str;

        // 규칙과 매칭이 되면 YES, 안되면 NO
        if (std::regex_match(str, re)) {
            answer.push_back("YES");
        }
        else {
            answer.push_back("NO");
        }

        --test_case;
    }

    for (auto a : answer) {
        cout << a << '\n';
    }

    return 0;
}