#include <iostream>
#include <array>

using std::cin;
using std::cout;

std::array<long long, 1000001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // n��°
    int n;

    // n��° �Է�
    cin >> n;

    // 0 ~ 9��°�� �� �ε��� ��ȣ�� �� �����ϴ� ���̴�.
    for (int i = 0; i < 10; ++i) {
        dp[i] = i;
    }

    // 0 1 2 3 4 5 6 7 8 9
    // 10 20 21 30 31 32 40 41 42 43...
    // 210 320 321 430 431 432 420 421 410...
    // ��Ģ�� ���� �ڸ� ���� �þ ������ ���� �ڸ�����
    // ���ڵ��� ���� �� �� �� �ִ�.
    if (n >= 10) {
        int cnt = 10;
        for (int i = 1; i <= n; ++i) {
            // ���� ���ں��� ���� ������ �������� �ݺ�
            for (int j = 0; j < (dp[i] % 10); ++j) {
                dp[cnt++] = dp[i] * 10 + j;
            }
        }
    }

    // �ִ� �����ϴ� ���� 9876543210�� �Ѿ�� -1 ���
    if (n > 1022) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[n] << '\n';
    }

    return 0;
}