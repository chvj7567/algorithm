#include <iostream>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

// ������ ���� �ּ� ����
std::array<int, 100001> dp = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �ڿ���
	int n;

	// �ڿ��� �Է�
	cin >> n;

	// �ʱ�ȭ
	std::fill(dp.begin(), dp.end(), 2e9);

	// 0�� �ڿ����� �������� ��Ÿ�� �� ����.
	dp[0] = 0;

	// 1 = 1^2
	// 2 = 1^2 + 1^2
	// 3 = 1^2 + 1^2 + 1^2
	// 4 = 2^2
	// 5 = 2^2 + 1^2
	// 6 = 2^2 + 1^2 + 1^2
	// 7 = 2^2 + 1^2 + 1^2 + 1^2
	// 8 = 2^2 + 2^2
	// 9 = 3^2
	// 10 = 3^2 + 1^2
	// 11 = 3^2 + 1^2 + 1^2
	// 12 = 2^2 + 2^2 + 2^2
	// ��Ģ�� ���� �Ʒ��� ���� �����غ��� �ȴ�.
	for (int i = 1; i <= n; ++i) {
		int tmp = std::sqrt(i);
		for (int j = 1; j <= tmp; ++j) {
			dp[i] = std::min(dp[i], dp[i - std::pow(j, 2)] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}