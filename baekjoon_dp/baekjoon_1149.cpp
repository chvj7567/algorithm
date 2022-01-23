#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// ���� ��
int n;
// �� ������ ĥ�� �� �� ���
std::vector<std::array<int, 3>> cost;
// �� ���� ���� ���� �ּҷ� ĥ�ϴ� ���(3���� ���)
std::array<std::array<int, 3>, 1001> dp;

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ���� �� �Է�
    cin >> n;

    // �� ���� ������ ĥ�� �� ��� ��� �Է�
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cost.push_back({ a,b,c });
    }

    // ù ��° ���� �� ������ ĥ�� ���� ��� ��� �̸� �Է�
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    // ù ��° ���� ĥ�ϴ� ��쿡 ���� 3������ ����
    // ���� ���� ĥ�� ���� �� ���� ���� ���ؼ� ĥ�Ѵ�.
    for (int i = 1; i < n; ++i) {
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    // 3���� ��� �� �ּڰ� ���
    cout << std::min(dp[n - 1][0], std::min(dp[n - 1][1], dp[n - 1][2])) << '\n';

    return 0;
}