#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // Ź���� ����, ���� ����
    // ����ġ�� ������ Ƚ��
    int length, width, k;
    // Ź�� ���� ���� ����
    std::array <std::string, 51> board;

    // Ź���� ����, ���� ���� �Է�
    cin >> length >> width;

    // Ź�� ���� ���� ���� �Է�
    for (int i = 0; i < length; ++i) {
        cin >> board[i];
    }

    // ����ġ�� ������ Ƚ�� �Է�
    cin >> k;

    // ����
    int answer = 0;
    for (int y = 0; y < length; ++y) {
        // �� ���� �����鿡 ���� ���� �ִ� ���� ��
        int lamp_off = 0;
        for (int x = 0; x < width; ++x) {
            if (board[y][x] == '0') {
                ++lamp_off;
            }
        }
        // ����ġ�� ������ Ƚ���� ���� �ִ� ���� ������ ���ƾ� �ϸ�,
        // ¦�� ���� ¦�� ��, Ȧ�� ���� Ȧ�� ���̾�� �Ѵ�.
        if (lamp_off <= k && lamp_off % 2 == k % 2) {
            // �������� �� ų �� �ִ� ���� ��
            int cnt = 0;
            for (int ty = 0; ty < length; ++ty) {
                // ���� �������� ���°� ���ٸ�
                if (board[y] == board[ty]) {
                    ++cnt;
                }
            }
            // ���� ���� �ִ��� ���� �����̴�.
            answer = std::max(answer, cnt);
        }
    }

    cout << answer << '\n';

    return 0;
}