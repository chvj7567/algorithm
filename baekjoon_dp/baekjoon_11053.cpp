#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ������ ��
int n;
// ����
std::array<int, 1001> seq = {};
// n���� ������ ������ ���� �� �����ϴ� �κ� ������ ��
std::array<int, 1001> dp = {};

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

    // �� ������ �����ϴ� �κ� ������ �ڱ� �ڽ��� �����Ѵ�.
    std::fill(dp.begin(), dp.end(), 1);

    // �����ϴ� �κ� �����̱� ���ؼ���
    // �ڱ� �ڽ� ���� ���� �߿� �ڱ⺸�� ���� ���� �����Ѵ�.
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 1; --j) {
            if (seq[i] > seq[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        answer = std::max(dp[i], answer);
    }

    cout << answer << '\n';

    return 0;
}