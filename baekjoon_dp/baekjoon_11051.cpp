#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n���� �� �� k���� ���� �̴� ����� ��
std::array<std::array<int, 1001>, 1001> dp = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �ڿ����� ����
	int n, k;

	// �ڿ����� ���� �Է�
	cin >> n >> k;

	// k�� 1�϶� �̴� ����� ���� n�� ����
	// k�� 0�̰ų� n�� k�� ���� �� �̴� ����� ���� 1
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = i;
		dp[0][i] = dp[i][i] = 1;
	}

	// ǥ�� �׷����� �� �� �ִ�.
	// (��-k ����)
	// (��-n �ڿ���)
	//   1 2 3 4
	//  |-------
	// 1|1 x x x 
	// 2|2 1 x x
	// 3|3 3 1 x
	// 4|4 6 4 1
	// �̸� ������ ���� ������ ����� ���� ����
	// ���� ���� ���� ���� �� ������ �հ� ����.
	// i�� �� j�� ��
	for (int i = 2; i <= k; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[k][n] << '\n';

	return 0;
}