#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// �ĵ��� ���� n�϶� �ﰢ���� ����
std::array<long long, 101> dp = {};

long long padoban(long long n) {
    // 1���� 7������ �����̸� �̸� �Է�
    switch (n) {
    case 1:
    case 2:
    case 3:
        return 1;
        break;
    case 4:
    case 5:
        return 2;
        break;
    case 6:
        return 3;
        break;
    case 7:
        return 4;
        break;
    default:
        break;
    }

    if (dp[n] != 0) {
        return dp[n];
    }
    // dp[1] = 1
    // dp[2] = dp[1] = 1
    // dp[3] = dp[1] = 1
    // dp[4] = dp[3] + dp[2] = 2
    // dp[5] = dp[4] = 2
    // dp[6] = dp[5] + dp[3] = 3
    // dp[7] = dp[6] + dp[1] = 4
    // dp[8] = dp[7] + dp[2] = 5
    // dp[9] = dp[8] + dp[3] = 7
    // dp[10] = dp[9] + dp[4] = 9
    // 8���� �ﰢ���� ������ ���� ��Ģ�� ���´�.
    return dp[n] = padoban(n - 1) + padoban(n - 5);
}

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �׽�Ʈ ���̽� ��
    int test_case, n;
    // ����
    std::vector<long long> answer;

    // �׽�Ʈ ���̽� �� �Է�
    cin >> test_case;

    while (test_case > 0) {
        // �ĵ��� ������ ��
        cin >> n;

        answer.push_back(padoban(n));

        --test_case;
    }

    for (auto a : answer) {
        cout << a << '\n';
    }

    return 0;
}