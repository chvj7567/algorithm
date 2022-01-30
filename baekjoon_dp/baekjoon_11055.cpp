#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ����
std::array<int, 1001> seq = {};
// ���� �������� �ϴ� ���� ���� ū ���� �κ� ������ ��
std::array<int, 1001> dp = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ��
	int n;

	// ������ �� �Է�
	cin >> n;

	// ���� �Է�, dp �ʱ�ȭ(�ڱ��ڽ��� �տ� ����)
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
		dp[i] = seq[i];
	}

	// �� �ε����� �������� ���� �κ� ���� ��
	// ���� ���� ū �κ��� ���Ѵ�.
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (seq[j] < seq[i]) {
				dp[i] = std::max(dp[i], dp[j] + seq[i]);
			}
		}
		answer = std::max(answer, dp[i]);
	}

	cout << answer << '\n';

	return 0;
}