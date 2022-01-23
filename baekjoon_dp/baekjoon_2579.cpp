#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ����� ��
int n;
// �� ����� ����
std::array<int, 301> score = {};
// �� ��ܿ� ���� �� ���� �� �ִ� �ְ� ����
std::array<int, 301> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ����� �� �Է�
    cin >> n;

    // �� ����� ���� �Է�
    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    // ù ��°, �� ��° ����� ���� �̸� �Է�
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];

    // �� ����� �������� �� ������ ���� �Ѵ�.
    // n��° ����� ������ ����(*�� ��� ���, 0�� ���� �ʴ� ���)
    // *0** �� **0*�� 2���� ��찡 �ִ�.
    for (int i = 3; i <= n; ++i) {
        dp[i] = std::max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}