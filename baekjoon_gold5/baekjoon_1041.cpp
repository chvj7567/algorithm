#include <iostream>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 주사위 갯수
    long long n;
    // 주사위 각 면의 점수
    std::array<int, 6> number = {};

    // 주사위 갯수 입력
    cin >> n;

    // 주사위 각 면의 점수 입력
    for (int i = 0; i < 6; ++i) {
        cin >> number[i];
    }

    // 주사위가 1개라면 모든 합에서
    // 최고 점수 하나만 빼면 정답
    if (n == 1) {
        int max_one = 0;
        for (auto a : number) {
            max_one = std::max(max_one, a);
        }

        int answer = 0;
        for (auto a : number) {
            answer += a;
        }
        cout << answer - max_one << '\n';
        return 0;
    }

    // 한 면일 때 최소 점수 저장
    int min_one = 51;
    for (auto a : number) {
        min_one = std::min(min_one, a);
    }

    // 붙어있는 두 면 점수의 합이 최소인 점수 저장
    int min_two = 101;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == j) {
                continue;
            }
            // 마주보는 3면 제외
            if ((i == 0 && j == 5) || (i == 5 && j == 0)) {
                continue;
            }
            if ((i == 1 && j == 4) || (i == 4 && j == 1)) {
                continue;
            }
            if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
                continue;
            }
            min_two = std::min(min_two, number[i] + number[j]);
        }
    }

    // 붙어있는 세 면 점수의 합이 최소인 점수 저장
    int min_three = 151;
    std::array<int, 4> sum = {};

    sum[0] = std::min(number[0] + number[1] + number[2], number[0] + number[1] + number[3]);
    sum[1] = std::min(number[0] + number[2] + number[4], number[0] + number[3] + number[4]);
    sum[2] = std::min(number[1] + number[2] + number[5], number[1] + number[3] + number[5]);
    sum[3] = std::min(number[2] + number[4] + number[5], number[3] + number[4] + number[5]);

    for (auto a : sum) {
        min_three = std::min(min_three, a);
    }

    // 주사위를 n3으로 두었을 때
    // 최상층 각 모서리                (세 면) : 4
    // 최상층 각 변                    (두 면) : (n - 2) * 4
    // 최상층의 각 모서리 각 변 제외   (한 면) : (n - 2) * (n - 2)
    // 최상층을 제외한 각 모서리       (두 면) : (n - 1) * 4
    // 최상층과 각 모서리 제외         (한 면) : (n - 2) * (n - 1) * 4
    std::array<long long, 5> part = {};
    long long one = min_one;
    long long two = min_two;
    long long three = min_three;

    part[0] = (two * 4) * (n - 1);
    part[1] = (three) * 4;
    part[2] = one * (n - 2) * (n - 1) * 4;
    part[3] = (two) * (n - 2) * 4;
    part[4] = one * std::pow(n - 2, 2);

    long long answer = 0;
    for (auto a : part) {
        answer += a;
    }

    cout << answer << '\n';

    return 0;
}