#include <iostream>
#include <array>

using std::cin;
using std::cout;

// �� ������ ���Կ� ��ġ
std::array<std::array<int, 2>, 101> p = {};
// ������ ��Ƽ�� ���Կ� ���� ���� �� �ִ� �ִ� ��ġ
std::array<int, 100001> dp = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��ǰ�� ���� �賶�� ��Ƽ�� ����
	int n, k;

	// ��ǰ�� ���� �賶�� ��Ƽ�� ���� �Է�
	cin >> n >> k;

	// �� ������ ���Կ� ��ġ �Է� ��
	// �� ������ ���� ���� ���� ���� ���� ������.
	// �� ������ ���� ���� ������ ��Ƽ�� ���԰� �����ʴ� ������
	// ����ϵ�, �� ������ �����ʰ� �ٸ� �� �־��� ���� �� ��
	// �ִ��� �����Ѵ�.
	for (int i = 1; i <= n; ++i) {
		cin >> p[i][0] >> p[i][1];
		for (int j = k; j >= 1; --j) {
			if (j >= p[i][0]) {
				dp[j] = std::max(dp[j], dp[j - p[i][0]] + p[i][1]);
			}
		}
	}

	cout << dp[k] << '\n';

	return 0;
}