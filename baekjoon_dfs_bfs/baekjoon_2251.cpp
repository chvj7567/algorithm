#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// ����
std::vector<int> answer;
// �� ���� ũ��
std::array<int, 3> bucket;
// ���� ���� �� �ִ� ����� �� Ȯ��
std::array<std::array<std::array<int, 201>, 201>, 201> visited;
// ���� �ű� ����� ��� ��ǥ
std::array<int, 6> from{ 0,0,1,1,2,2 };
std::array<int, 6> to{ 1,2,0,2,0,1 };

void dfs(int a, int b, int c) {
	// �̹� Ȯ���� ���� ���̸� ����
	if (visited[a][b][c]) {
		return;
	}
	// ���� �� Ȯ��
	visited[a][b][c] = true;

	// a�� ���� ���� 0�̸� ���� push
	if (a == 0) {
		answer.push_back(c);
	}

	for (int i = 0; i < 6; ++i) {
		// ���� ���� ��
		std::array<int, 3> water{ a,b,c };
		// ���� �ű� ��
		int cur_from = from[i];
		// ���� �Ű��� ��
		int cur_to = to[i];
		// ���� �Ű��� ���� ���� ����
		int space = bucket[cur_to] - water[cur_to];
		// ���� �� �� ������ �ִٸ�
		// ���� �� �ű��.
		if (water[cur_from] <= space) {
			water[cur_to] += water[cur_from];
			water[cur_from] -= water[cur_from];
		}
		// ���� �� �� ������ ���ٸ�
		// ���� ���� ��ŭ�� �ű��.
		else {
			water[cur_from] -= space;
			water[cur_to] += space;
		}
		dfs(water[0], water[1], water[2]);
	}
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ���� ũ�� �Է�
	for (int i = 0; i < 3; ++i) {
		cin >> bucket[i];
	}

	dfs(0, 0, bucket[2]);

	std::sort(answer.begin(), answer.end());

	for (auto i : answer) {
		cout << i << ' ';
	}

	return 0;
}