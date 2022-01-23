#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ���� ��
int n;
// �������� ��
std::array<int, 10001> wine = {};
// n���� �����ְ� ���� �� ���� �� �ִ� �ִ� ��
std::array<int, 10001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ���� �� �Է�
    cin >> n;

    // �������� �� �Է�
    for (int i = 1; i <= n; ++i) {
        cin >> wine[i];
    }

    // ù ��°, �� ��° �������� �ִ� �̸� �Է�
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // n���� �����ָ� �ִ�� ���ô� ����� ����
    // (*�� ���ô� ���, 0�� ������ �ʴ� ���)
    // *0**, *0* ������ n��° �����ָ� ���ô� ����
    // *0 ������ n��° �����ָ� ������ �ʴ� ��찡 �ִ�.
    for (int i = 3; i <= n; ++i) {
        dp[i] = std::max(dp[i - 2] + wine[i], std::max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1]));
    }

    cout << dp[n] << '\n';

    return 0;
}