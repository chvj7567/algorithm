#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ���̰� n�϶� ������ ����� ��
std::array<long long, 1000001> dp = {};

// Ÿ���� ����� ���� ����
// dp[1] = 1
// dp[2] = 11, 00
// dp[3] = 111, 100, 001
// dp[4] = 1111, 1100, 1001, 0011, 0000
// �̷� ��Ģ��� �Ǻ���ġ ����ó��
// �þ�� ���� Ȯ���� �� �ִ�.
long long tile(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    return dp[n] = (tile(n - 2) + tile(n - 1)) % 15746;
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