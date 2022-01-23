#include <iostream>
#include <array>

using std::cin;
using std::cout;

// �ﰢ���� ũ��
int n;
// �ﰢ���� ����
std::array<std::array<int, 501>, 501> tri = {};
// ���� ���� ���� ���� �� �ִ� �ִ� ��
std::array<std::array<int, 501>, 501> dp = {};

int maxValue(int y, int x) {
    // ������ ���� ���� �ڱ� �ڽ��� ��ȯ
    if (y == n - 1) {
        return tri[y][x];
    }

    if (dp[y][x] != 0) {
        return dp[y][x];
    }

    // �ش� ���� ���� ���� ���� ���� �ִ��� �ջ�
    return dp[y][x] = tri[y][x] + std::max(maxValue(y + 1, x), maxValue(y + 1, x + 1));
}
int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �ﰢ���� ũ�� �Է�
    cin >> n;

    // �ﰢ���� ���� �Է�
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> tri[i][j];
        }
    }

    cout << maxValue(0, 0) << '\n';

    return 0;
}