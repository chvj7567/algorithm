#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n��° �ڸ� ���϶� �������� �� ���ڰ� �ö� ������ ��ģ���� ��
std::array<std::array<long long, 91>, 91> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    // �� �ڸ� ���϶��� 1�ۿ� ���� ����
    dp[1][0] = 0;
    dp[1][1] = 1;

    // �� ���ڰ� 0�϶��� 0�Ǵ� 1
    // �� ���ڰ� 1�϶��� 1�� �� �� �ۿ� ����.
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1] << '\n';

    return 0;
}