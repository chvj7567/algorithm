#include <iostream>
#include <string>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

// 보드의 세로 가로 길이
int length, width;
// 보드 상태
std::array <std::string, 10> board;

std::string maxNum(int y, int x, int ny, int nx) {
    // 범위를 벗어나면 종료
    if (y < 0 || y >= length || x < 0 || x >= width) {
        return "";
    }
    // 숫자가 문자 형태이기에 문자열로 합침
    std::string str;
    // 처음 숫자를 넣는다.
    str += board[y][x];
    // 이후 이동된 자표를 순서대로 넣는다.
    str += maxNum(y + ny, x + nx, ny, nx);
    // 최종 숫자 문자열 반환
    return str;
}
int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 보드의 세로 가로 길이 입력
    cin >> length >> width;

    // 보드 상태 입력
    for (int i = 0; i < length; ++i) {
        cin >> board[i];
    }

    // 제곱수가 있는지 확인
    bool check = false;
    // 정답
    int answer = 0;
    // 보드의 가로, 세로의 길이가 1이면 해당 숫자가
    // 제곱수이면 그대로 반환
    if (length == 1 && width == 1) {
        int num = stoi(board[0]);
        if (num == std::pow((int)std::sqrt(num), 2)) {
            check = true;
            answer = std::max(answer, num);
        }
    }
    else {
        // 각 좌표에서 시작하면서 제곱수 찾기
        for (int y = 0; y < length; ++y) {
            for (int x = 0; x < width; ++x) {
                // 갈 수 있는 모든 방향 지정
                for (int a = -length + 1; a < length; ++a) {
                    for (int b = -width + 1; b < width; ++b) {
                        // 증/가감치가 0, 0 이면 움직이지 않기 때문에 패스
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        // 최종 반환된 문자열을 받는다.
                        std::string s = maxNum(y, x, a, b);
                        // 해당 문자열이 제곱수인지 판단한다.
                        // 단, 1210의 경우 앞의 121이 제곱수이므로
                        // 121만 추출하여 제곱수로 판단한다.
                        // 기준은 인덱스 0부터 연결된 인덱스까지만 가능하다.
                        for (int i = s.size(); i >= 1; --i) {
                            int num = stoi(s.substr(0, i));
                            if (num == std::pow((int)std::sqrt(num), 2)) {
                                check = true;
                                answer = std::max(answer, num);
                            }
                        }
                    }
                }
            }
        }
    }

    // 제곱수가 있다면 최대 제곱수 반환
    // 제곱수가 없다면 -1 반환
    if (check) {
        cout << answer << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}