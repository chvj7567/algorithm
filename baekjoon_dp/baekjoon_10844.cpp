#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n��° �ڸ� ���� �������� �� ���ڰ� �� �� ������ ��ܼ��� ��
std::array<std::array<int, 11>, 101> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �ڸ� ��
    int n;

    // �ڸ� �� �Է�
    cin >> n;

    // �� �ڸ� �� �϶� �̸� �Է�
    for (int i = 1; i < 10; ++i) {
        dp[1][i] = 1;
    }

    // �� �ڸ� ������ ���
    for (int i = 2; i <= n; ++i) {
        // �� ���ڰ� 0�϶��� ���� ���ڰ� 1,
        // �� ���ڰ� 9�϶��� ���� ���ڰ� 8
        // �ۿ� ���� ���Ѵ�.
        dp[i][0] = (dp[i - 1][1]) % 1000000000;
        dp[i][9] = (dp[i - 1][8]) % 1000000000;
        // �� ���ڰ� 2 ~ 8�϶��� -1�� ���ڿ� +1�� ���ڰ� �� �� �ִ�.
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    int answer = 0;
    for (int i : dp[n]) {
        answer += i;
        answer %= 1000000000;
    }

    cout << answer << '\n';

    return 0;
}