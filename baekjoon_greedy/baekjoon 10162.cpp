#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void minButton(int& cook_time, int& cnt, int button_time) {
    // �ش� �ð��� ���� ���� �ð� ��ŭ�� ���鼭 Ƚ���� �ð��� ����Ѵ�.
    while (cook_time >= button_time) {
        cook_time -= button_time;
        cnt++;
    }
}
int main() {
    // �丮 �ð�
    int cook_time;
    // 5�� ��ư Ƚ��, 1�� ��ư Ƚ��, 10�� ��ư Ƚ��
    int cnt_5min = 0, cnt_1min = 0, cnt_10sec = 0;

    // �丮 �ð� �Է�
    cin >> cook_time;

    minButton(cook_time, cnt_5min, 300);
    minButton(cook_time, cnt_1min, 60);
    minButton(cook_time, cnt_10sec, 10);

    // �丮 �ð��� ���� �� ���ٸ� -1 ��ȯ
    if (cook_time != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << cnt_5min << " " << cnt_1min << " " << cnt_10sec << endl;

    return 0;
}