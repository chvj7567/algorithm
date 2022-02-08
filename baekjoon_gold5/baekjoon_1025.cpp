#include <iostream>
#include <string>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

// ������ ���� ���� ����
int length, width;
// ���� ����
std::array <std::string, 10> board;

std::string maxNum(int y, int x, int ny, int nx) {
    // ������ ����� ����
    if (y < 0 || y >= length || x < 0 || x >= width) {
        return "";
    }
    // ���ڰ� ���� �����̱⿡ ���ڿ��� ��ħ
    std::string str;
    // ó�� ���ڸ� �ִ´�.
    str += board[y][x];
    // ���� �̵��� ��ǥ�� ������� �ִ´�.
    str += maxNum(y + ny, x + nx, ny, nx);
    // ���� ���� ���ڿ� ��ȯ
    return str;
}
int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ������ ���� ���� ���� �Է�
    cin >> length >> width;

    // ���� ���� �Է�
    for (int i = 0; i < length; ++i) {
        cin >> board[i];
    }

    // �������� �ִ��� Ȯ��
    bool check = false;
    // ����
    int answer = 0;
    // ������ ����, ������ ���̰� 1�̸� �ش� ���ڰ�
    // �������̸� �״�� ��ȯ
    if (length == 1 && width == 1) {
        int num = stoi(board[0]);
        if (num == std::pow((int)std::sqrt(num), 2)) {
            check = true;
            answer = std::max(answer, num);
        }
    }
    else {
        // �� ��ǥ���� �����ϸ鼭 ������ ã��
        for (int y = 0; y < length; ++y) {
            for (int x = 0; x < width; ++x) {
                // �� �� �ִ� ��� ���� ����
                for (int a = -length + 1; a < length; ++a) {
                    for (int b = -width + 1; b < width; ++b) {
                        // ��/����ġ�� 0, 0 �̸� �������� �ʱ� ������ �н�
                        if (a == 0 && b == 0) {
                            continue;
                        }
                        // ���� ��ȯ�� ���ڿ��� �޴´�.
                        std::string s = maxNum(y, x, a, b);
                        // �ش� ���ڿ��� ���������� �Ǵ��Ѵ�.
                        // ��, 1210�� ��� ���� 121�� �������̹Ƿ�
                        // 121�� �����Ͽ� �������� �Ǵ��Ѵ�.
                        // ������ �ε��� 0���� ����� �ε��������� �����ϴ�.
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

    // �������� �ִٸ� �ִ� ������ ��ȯ
    // �������� ���ٸ� -1 ��ȯ
    if (check) {
        cout << answer << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}