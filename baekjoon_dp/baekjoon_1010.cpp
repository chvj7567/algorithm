#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// ���� �ٸ� ���� ���� �ٸ� ���� �־��� �� ������ �ٸ� ��
std::array<std::array<int, 31>, 31> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ����
    std::vector<int> answer;
    // �׽�Ʈ ���̽� ����
    // ����, ���� ����Ʈ ��
    int test_case, n, m;

    // �׽�Ʈ ���̽� �� �Է�
    cin >> test_case;

    while (test_case > 0) {
        // ����, ���� ����Ʈ �� �Է�
        cin >> n >> m;

        // ���� ����Ʈ ���� 1�� �϶� ������ �ٸ� ����
        // ���� ����Ʈ ���� ����.
        // ����, ���� ����Ʈ ���� ������ ������ �ٸ����� 1���̴�.
        for (int i = 1; i <= m; ++i) {
            dp[1][i] = i;
            dp[i][i] = 1;
        }

        // ǥ�� �׷����� �� �� �ִ�.
        // (��-���� ����Ʈ ��)
        // (��-���� ����Ʈ ��)
        //   1 2 3 4
        //  |-------
        // 1|1 x x x 
        // 2|2 1 x x
        // 3|3 3 1 x
        // 4|4 6 4 1
        // �̸� ������ ���� ������ ����� ���� ����
        // ���� ���� ���� ���� �� ������ �հ� ����.
        // i�� �� j�� ��
        for (int i = 2; i <= n; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }

        answer.push_back(dp[n][m]);

        --test_case;
    }

    for (int i : answer) {
        cout << i << '\n';
    }

    return 0;
}