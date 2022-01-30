#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n��° �ڸ��� �� ���ڰ� �ö� ������ ������ ���� ��
std::array<std::array<int, 11>, 1001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �ڸ� ��
    int n;

    // �ڸ� �� �Է�
    cin >> n;

    // 0���� 9�� ��� ���������̴�.
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }

    // 0�̸� 0���� 9���� �� �� �ְ�,
    // 1�̸� 1���� 9���� �� �� �ִ�.
    // ��, ���� ���ڰ� 0�̸� ������ 0���� 9������
    // ����� ���� ��� ���� �Ͱ� ����.
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            long long sum = 0;
            for (int k = j; k < 10; ++k) {
                sum += dp[i - 1][k];
            }
            dp[i][j] = sum % 10007;
        }
    }

    long long answer = 0;
    for (int i : dp[n]) {
        answer += i;
    }

    cout << answer % 10007 << '\n';

    return 0;
}