#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// �� ��ƼĿ�� ����
std::array<std::array<int, 2>, 100001> st = {};
// �� ��ƼĿ�� �������� ��� ����
std::array<std::array<int, 2>, 100001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ����
    std::vector<int> answer;
    // �׽�Ʈ ���̽� ���� ��ƼĿ ���� ��
    int test_case, n;

    // �׽�Ʈ ���̽� ��
    cin >> test_case;

    while (test_case > 0) {
        // ��ƼĿ ���� �� �Է�
        cin >> n;

        // �� ��ƼĿ�� ���� �Է�
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> st[j][i];
            }
        }

        // �ε����� 0���� �����Ͽ� 0�� 1���� ���� �ȴ�.
        // dp�� �ε��� ��ȣ�� �������� ����� �����̴�.
        // 2�������� ���� �̸� �����ش�.
        dp[0][0] = st[0][0];
        dp[0][1] = st[0][1];
        dp[1][0] = dp[0][1] + st[1][0];
        dp[1][1] = dp[0][0] + st[1][1];

        // 3�� �̻���� ����� ���� 4������
        // x O x  0 x 0  x x 0  0 x x
        // 0 x 0, x 0 x, 0 x x, x x 0
        // �� ��츦 �����ָ� �ȴ�.
        for (int i = 2; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][1], dp[i - 2][1]) + st[i][0];
            dp[i][1] = std::max(dp[i - 1][0], dp[i - 2][0]) + st[i][1];
        }

        answer.push_back(std::max(dp[n - 1][0], dp[n - 1][1]));

        --test_case;
    }

    for (int i : answer) {
        cout << i << '\n';
    }

    return 0;
}