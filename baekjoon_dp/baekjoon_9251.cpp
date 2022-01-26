#include <iostream>
#include <array>
#include <vector>
#include <string>

using std::cin;
using std::cout;

// �� ���ڿ�
std::string s1, s2;
// �� ���ڿ��� ���̿� ���� �ִ� LCS ��
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �� ���ڿ� �Է�
    cin >> s1 >> s2;

    // �� ���ڿ��� �������� ���� ���� �ٸ� ���� ������.
    // ���� ��� ���� LCS���� 1���� �÷��ָ� �ǰ�,
    // �ٸ��ٸ� �ε����� ���� �ε����� �Ѱ��־�� �ϴµ�
    // �� ���� ��츦 ���ؼ� max ���� �־��ش�.
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';

    return 0;
}