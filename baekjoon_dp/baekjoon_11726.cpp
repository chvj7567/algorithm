#include <iostream>
#include <array>

using std::cin;
using std::cout;

// �� ���̿� ���� Ÿ���� ä�� �� �ִ� ����� ��
std::array<int, 1001> dp = {};

int tile(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    // Ÿ�� ����� ���� ���̰� 1�� �þ �� ����� �� ���� ����
    // ���̰� 2�� �þ�� ���� ���̰� 1�϶� ����� ��쿡
    // �� ������ ���ԵǹǷ� ������ ��� �� ���� ��찡 �ִ�.
    return dp[n] = (tile(n - 2) + tile(n - 1)) % 10007;
}
int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ����
    int n;

    // ���� �Է�
    cin >> n;

    cout << tile(n) << '\n';

    return 0;
}