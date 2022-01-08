#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void minButton(int& cook_time, int& cnt, int button_time) {
    // 해당 시간에 대해 단위 시간 만큼을 빼면서 횟수와 시간을 계산한다.
    while (cook_time >= button_time) {
        cook_time -= button_time;
        cnt++;
    }
}
int main() {
    // 요리 시간
    int cook_time;
    // 5분 버튼 횟수, 1분 버튼 횟수, 10초 버튼 횟수
    int cnt_5min = 0, cnt_1min = 0, cnt_10sec = 0;

    // 요리 시간 입력
    cin >> cook_time;

    minButton(cook_time, cnt_5min, 300);
    minButton(cook_time, cnt_1min, 60);
    minButton(cook_time, cnt_10sec, 10);

    // 요리 시간을 맞출 수 없다면 -1 반환
    if (cook_time != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << cnt_5min << " " << cnt_1min << " " << cnt_10sec << endl;

    return 0;
}