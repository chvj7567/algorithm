#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// ������ �������� �ּ� �ð� ���
std::array<int, 100001> minTime;
// ���� �̵��� ��� ��ġ
std::array<int, 3> next = { -1, 1, 2 };

int find(int n, int k) {
	// �� ��ġ�� �����ϴٸ� ������ ������Ƿ� ����
	if (n == k) {
		return 0;
	}

	// ť�� ���� ��ġ ���� �� üũ
	std::queue<int> q;
	minTime[n] = 1;
	q.push(n);

	while (!q.empty()) {
		// ���� ��ġ
		int cur_n = q.front();
		q.pop();

		// ������ ������� �ݺ��� ����
		if (cur_n == k) {
			return minTime[cur_n] - 1;
		}

		// ������ �� �ִ� 3���� ���
		for (int i = 0; i < 3; ++i) {
			// ������ ��� ��ġ
			int next_n = cur_n;
			// �����̵��� �� ��� ��ġ
			if (i == 2) {
				next_n *= next[i];
			}
			// �� �ڷ� �̵��� ��� ��ġ
			else {
				next_n += next[i];
			}
			// ��ü ��ġ�� ����� �ʰ� �ѹ� ����ģ ��ġ�� �ƴ϶��
			if (!(next_n < 0 || next_n>100000) && !minTime[next_n]) {
				// ���� ��ġ�� ��� �ð� 1 �߰�
				minTime[next_n] = minTime[cur_n] + 1;
				q.push(next_n);
			}
		}
	}
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �������� ��ġ�� ������ ��ġ
	int n, k;

	// �������� ��ġ�� ������ ��ġ �Է�
	cin >> n >> k;

	cout << find(n, k) << '\n';

	return 0;
}