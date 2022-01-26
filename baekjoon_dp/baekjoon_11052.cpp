#include <iostream>
#include <array>

using std::cin;
using std::cout;
// �� ī�� ���� ����
std::array<int, 1001> card = {};
// n���� ī�带 �춧 �ִ� ����
std::array<int, 1001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ������ ī�� ��
    int n;

    // ������ ī�� �� �Է�
    cin >> n;

    // ī���� ���� �Է�
    for (int i = 1; i <= n; ++i) {
        cin >> card[i];
    }

    // 1���� �춧�� 1��¥�� �Ѹ� ���� ����
    dp[1] = card[1];

    // dp�� �ε��� ���� card ���� �ε��� ����
    // ���Ϸ��� dp�� �ε��� ���� �ȴٴ� ��Ģ�� �Ʒ��� ���� �� �� �ִ�.
    // �װ��� ���� ������ ���� ���Ͽ� max ���� dp�� �������ش�.
    // dp[2] = max(dp[1] + card[1], dp[0] + card[2])
    // dp[3] = max(dp[2] + card[1], dp[1] + card[2], dp[0], card[3])
    // dp[4] = max(dp[3] + card[1], dp[2] + card[2], dp[1] + card[3], dp[0] + card[4])
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = std::max(dp[i], dp[i - j] + card[j]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}