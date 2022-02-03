#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ����
    std::vector<int> answer;
    // �׽�Ʈ ���̽� ��
    int test_case;

    // �׽�Ʈ ���̽� �� �Է�
    cin >> test_case;

    while (test_case > 0) {
        // ��� ������ ���� ����
        long long x, y;

        // ��� ������ ���� ���� �Է�
        cin >> x >> y;

        // �̵� �Ÿ� y�� ����
        y -= x;

        // �̵� �Ÿ��� ���ٸ� 0�� ����
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
        // ��Ģ�� ���� �� �������� �� ������ ���� ��(?) ���°� �ȴ�.
        // ���� �� ���̸� ������ ������ 1�� �����Ҷ��� �ְ� 2�� ������ ���� �ִ�.
        // 2�� 3�� ������ 4�� 9 ���� �� �� �� 5, 6�� 4���� �̵� Ƚ���� 1�� ����
        // 7�� 8�� �̵� Ƚ���� 2�� ����.
        
        // �̵��Ÿ��� ������(���� �ڸ� �̸��� ����)
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