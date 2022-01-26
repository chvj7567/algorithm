#include <iostream>
#include <array>

using std::cin;
using std::cout;

std::array<int, 1001> dp = {};

int tile(int n) {
    // ���簢���� ���̰� 1�� 2�϶��� ����
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }
    if (dp[n] != 0) {
        return dp[n];
    }

    // ���̰� 1�� �þ���� 1 x 2 Ÿ���� ���̴� ��� �� ����
    // ���̰� 2�� �þ���� 2 x 1 Ÿ���� ���̴� ��� �� ������
    // 2 x 2 Ÿ���� ���̴� ��� �� ������ ���ؼ� �� ���� ���
    // 1 x 2 Ÿ���� ���̴� ���� ���̰� 1�þ���� ���̴� ��쿡 ����
    return dp[n] = (tile(n - 2) * 2 + tile(n - 1)) % 10007;
}
int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ���簢���� ���� ����
    int n;

    // ���� ���� �Է�
    cin >> n;

    cout << tile(n) << '\n';

    return 0;
}