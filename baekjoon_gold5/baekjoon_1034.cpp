#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;

int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 탁자의 세로, 가로 길이
    // 스위치를 누르는 횟수
    int length, width, k;
    // 탁자 위의 램프 상태
    std::array <std::string, 51> board;

    // 탁자의 세로, 가로 길이 입력
    cin >> length >> width;

    // 탁자 위의 램프 상태 입력
    for (int i = 0; i < length; ++i) {
        cin >> board[i];
    }

    // 스위치를 누르는 횟수 입력
    cin >> k;

    // 정답
    int answer = 0;
    for (int y = 0; y < length; ++y) {
        // 한 행의 램프들에 대해 꺼져 있는 램프 수
        int lamp_off = 0;
        for (int x = 0; x < width; ++x) {
            if (board[y][x] == '0') {
                ++lamp_off;
            }
        }
        // 스위치를 누르는 횟수가 꺼져 있는 램프 수보다 많아야 하며,
        // 짝수 개면 짝수 번, 홀수 개면 홀수 번이어야 한다.
        if (lamp_off <= k && lamp_off % 2 == k % 2) {
            // 램프들을 다 킬 수 있는 행의 수
            int cnt = 0;
            for (int ty = 0; ty < length; ++ty) {
                // 행의 램프들의 상태가 같다면
                if (board[y] == board[ty]) {
                    ++cnt;
                }
            }
            // 행의 수가 최대인 것이 정답이다.
            answer = std::max(answer, cnt);
        }
    }

    cout << answer << '\n';

    return 0;
}