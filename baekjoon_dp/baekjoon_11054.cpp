#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ����
std::array<int, 1001> seq = {};
// �����ϴ� �κ� ����
std::array<int, 1001> dp1 = {};
// �����ϴ� �κ� ����
std::array<int, 1001> dp2 = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ��
	int n;

	// ������ �� �Է�
	cin >> n;

	// ���� �Է�
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
	}

	// 1�� �ʱ�ȭ
	std::fill(dp1.begin(), dp1.end(), 1);
	std::fill(dp2.begin(), dp2.end(), 1);

	// �����ϴ� �κ� ������ �ִ� ����(������� ������ ���� �κ�)
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (seq[j] < seq[i]) {
				dp1[i] = std::max(dp1[i], dp1[j] + 1);
			}
		}
	}

	// �����ϴ� �κ� ������ �ִ� ����(������� ������ ���� �κ�)
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j) {
			if (seq[j] < seq[i]) {
				dp2[i] = std::max(dp2[i], dp2[j] + 1);
			}
		}
	}

	// ������ �Ǵ� ���� 2�� ���Ǿ����Ƿ� -1
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		answer = std::max(answer, dp1[i] + dp2[i] - 1);
	}

	cout << answer << '\n';

	return 0;
}