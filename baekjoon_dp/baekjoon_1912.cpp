#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ������ ���� ����
int n, answer = -2e9;
// ����
std::array<int, 100001> seq = {};
// n���� ������ ���ӵ� ���� ���� �ִ�
std::array<int, 100001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ������ �� �Է�
    cin >> n;

    // ���� �Է�
    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
    }

    // ù��° ���� �̸� �Է�
    dp[1] = seq[1];

    // ���ӵ� ���� �� �� �ִ��� ���ϱ� ���ؼ���
    // ���� ������ ���� ������ �ƴϰų�
    // �ش� ��°�� ���� ������ �� ������ ���� ���� ���̴�.
    // �� ��찡 �ƴ� ���� �ش� ��° ���� �����ְ�
    // �� ��쿡 ���Ե� ���� �ش� ��° ���� �������� ���� ���Ѵ�.
    int answer = -2e9;
    for (int i = 2; i <= n; ++i) {
        if (!(dp[i - 1] < 0 || dp[i - 1] + seq[i] < 0)) {
            dp[i] = dp[i - 1] + seq[i];
        }
        else {
            dp[i] = seq[i];
        }

        answer = std::max(answer, dp[i]);
    }

    // ù ��° ���� �ִ� ���� �񱳸� ���� �������Ƿ� ���Ѵ�.
    answer = std::max(answer, dp[1]);

    cout << answer << '\n';

    return 0;
}