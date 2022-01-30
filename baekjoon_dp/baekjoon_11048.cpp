#include <iostream>
#include <array>

using std::cin;
using std::cout;

// �ش� ��ǥ�� ������ �� ���� �� �ִ� �ִ� ����
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �̷��� ����, ���� ����
    int n, m;

    // �̷��� ����, ���� ���� �Է�
    cin >> n >> m;

    // �̷��� ���� ���� �Է�
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> dp[y][x];
        }
    }

    // ���ٷ� �� �� ���� �� �ִ� ������ ����
    for (int y = 1; y <= n; ++y) {
        dp[y][1] += dp[y - 1][1];
    }

    // �������� �� �� ���� �� �ִ� ������ ����
    for (int x = 1; x <= m; ++x) {
        dp[1][x] += dp[1][x - 1];
    }

    // �� �� �ִ� 3���� ��� �� ���� �� �ִ� �ִ� ���� ������ �ڱ� �ڽŰ� ���Ѵ�.
    for (int y = 2; y <= n; ++y) {
        for (int x = 2; x <= m; ++x) {
            dp[y][x] += std::max(dp[y - 1][x - 1], std::max(dp[y - 1][x], dp[y][x - 1]));
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}