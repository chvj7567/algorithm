#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ����� �ɸ��� �� �� �� ���
std::array<std::pair<int, int>, 16> cst = {};
// n�ϱ��� ������ �� ��� �ִ� ����
std::array<int, 16> dp = {};

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ������ ���� ��
    int n;

    // ������ ���� �� �Է�
    cin >> n;

    // ��� ���� �Է�
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        cst[i] = { a, b };
    }
    
    for (int i = 1; i <= n; ++i) {
        // i��¥�� ����� ���� ���
        int day = i + cst[i].first;
        // n�Ͽ� 1��ġ ���� �� ��쵵 �����Ƿ� n + 1�ϱ���
        if (day <= n + 1) {
            // �������� i��¥�� �� ��� ����� �������� �ִ�
            dp[day] = std::max(dp[day], dp[i] + cst[i].second);
        }
        // n��° ���� ����� n��°�� 1��ġ ���� �� ��츦 �����ؼ�
        // n + 1��° ���� ���� �� �� �ִ� ����
        dp[i + 1] = std::max(dp[i], dp[i + 1]);
    }

    cout << dp[n + 1] << '\n';

    return 0;
}