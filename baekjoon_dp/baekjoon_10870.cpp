#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n��° �Ǻ���ġ�� ��
std::array<int, 21> dp = {};

int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // ����� ���� �ִٸ�
    // ����� dp�� ��ȯ
    if (dp[n] != 0) {
        return dp[n];
    }
    // dp�� �� ���� �� ��ȯ
    return dp[n] = fibo(n - 2) + fibo(n - 1);
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

    cout << fibo(n) << '\n';

    return 0;
}