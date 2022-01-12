#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ ���� ����
	int n, cnt = 0;
	// �� ���� �� ����
	std::vector<int> score;

	// ���� �� �Է�
	cin >> n;

	// �� ���� �� ���� �Է�
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		score.push_back(tmp);
	}

	// ū ���� ���� ���� ���� ������
	// �Ʒ� ������ ū ���� �̻��̸� 1�� ����
	for (int i = n - 1; i > 0; --i) {
		while (score[i] <= score[i - 1]) {
			score[i - 1] -= 1;
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}