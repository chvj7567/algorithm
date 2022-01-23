#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// �� ���� ���� �Ǻ���ġ ���� �� 0�� 1�� ȣ���ϴ� ��
std::array<std::pair<int, int>, 41> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ���ڿ� �׽�Ʈ ���̽� ��
    int n, test_case;
    // �� ���ڸ� ��� �迭
    std::vector<int> number;

    // �׽�Ʈ ���̽� �� �Է�
    cin >> test_case;

    while (test_case > 0) {
        cin >> n;

        number.push_back(n);

        // 0�� 1�϶� 0�� 1�� ��µǴ� �� �̸� �Է�
        dp[0] = { 1,0 };
        dp[1] = { 0,1 };

        // �Ǻ���ġ�� return���� ���� ���� �� �� �ִ�.
        for (int i = 2; i <= n; ++i) {
            dp[i] = { dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second };
        }
        --test_case;
    }

    for (int i : number) {
        cout << dp[i].first << " " << dp[i].second << '\n';
    }

    return 0;
}