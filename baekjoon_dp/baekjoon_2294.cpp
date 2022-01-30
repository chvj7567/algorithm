#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ������ ����
std::array<int, 101> coin = {};
// ������ �ּ� ����
std::array<int, 100001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ������ ������ ��ǥ �ݾ�
    int n, k;

    // ������ ������ ��ǥ �ݾ� �Է�
    cin >> n >> k;
    // �ʱ�ȭ
    std::fill(dp.begin(), dp.end(), 10001);

    // �� ������ ��ġ�� �Է� ��
    // �� ������ �ݾ��� ���� �ش� ������ ���� ����
    // ������ �ּ� �����̴�.
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
        dp[coin[i]] = 1;
    }

    // ������������ ����
    std::sort(coin.begin(), coin.end(), std::greater<int>());

    // ��ǥ �ݾ��� 7�̰� 2, 5���� ���� ���
    //   1 2 3 4 5 6 7
    // 2 0 1 0 2 0 3 1
    // 5 0 0 0 0 1 0 1
    // �� ó�� ǥ�� ����� �� �� �ִµ� 7���� ���� ��
    // 7���� �ִ� ��ġ�� �������� ���� �� ������
    // 7 - 5 = 2���ǹǷ� 2�϶� �ּ� ������ 1��
    // ������ 5�� �ϳ� �� �Ͱ� ������ +1 �� ��ġ�� ���ʴ��
    // ���ϸ� �ȴ�.
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > coin[j]) {
                dp[i] = std::min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    if (dp[k] == 10001) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[k] << '\n';
    }

    return 0;
}