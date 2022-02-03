#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정답
    std::vector<int> answer;
    // 테스트 케이스 수
    int test_case;

    // 테스트 케이스 수 입력
    cin >> test_case;

    while (test_case > 0) {
        // 출발 지점과 도착 지점
        long long x, y;

        // 출발 지점과 도착 지점 입력
        cin >> x >> y;

        // 이동 거리 y에 저장
        y -= x;

        // 이동 거리가 없다면 0이 정답
        if (y == 0) {
            answer.push_back(0);
            --test_case;
            continue;
        }

        // 1 : 1
        // 2 : 1 1
        // 3 : 1 1 1 
        // 4 : 1 2 1
        // 5 : 1 2 1 1
        // 6 : 1 2 2 1
        // 7 : 1 2 2 1 1
        // 8 : 1 2 2 2 1
        // 9 : 1 2 3 2 1
        // 규칙을 보면 각 제곱수가 될 때마다 수가 산(?) 형태가 된다.
        // 제곱 수 사이를 반으로 나누어 1이 증가할때가 있고 2가 증가할 때가 있다.
        // 2와 3을 제곱한 4와 9 사이 중 반 인 5, 6은 4보다 이동 횟수가 1이 많고
        // 7과 8은 이동 횟수가 2가 많다.
        
        // 이동거리의 제곱근(일의 자리 미만은 버림)
        int tmp = (int)std::sqrt(y);
        if (std::pow(tmp, 2) == y) {
            answer.push_back(tmp * 2 - 1);
        }
        else if (y < (std::pow(tmp, 2) + std::pow(tmp + 1, 2)) / 2) {
            answer.push_back(tmp * 2);
        }
        else {
            answer.push_back(tmp * 2 + 1);
        }

        --test_case;
    }

    for (auto a : answer) {
        cout << a << '\n';
    }

    return 0;
}