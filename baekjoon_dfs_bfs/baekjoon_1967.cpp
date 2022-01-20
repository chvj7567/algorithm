#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ����� ���� �� ���, ����
int n, end_n, answer = 0;
// Ʈ�� ����
std::array<std::vector<std::pair<int, int>>, 10001> tree;
// �湮 Ȯ��
std::array<bool, 10001> visited;

void dfs(int n, int d) {
	// �̹� �湮 �ߴٸ� ����
	if (visited[n]) {
		return;
	}
	// ���� �Ÿ��� �� ������
	// �Ÿ��� ��� ��ȣ ����
	if (answer < d) {
		answer = d;
		end_n = n;
	}

	// �湮 ó��
	visited[n] = true;

	// ���� ��ǥ ���
	for (int i = 0; i < tree[n].size(); ++i) {
		int next_n = tree[n][i].first;
		int next_d = tree[n][i].second;
		dfs(next_n, next_d + d);
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��� �� �Է�
	cin >> n;

	// Ʈ�� ���� �Է�
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		// �����
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	// ������ �������� ���� �� ���� ã��(���� ã��)
	dfs(1, 0);
	
	// �湮 Ȯ�� �ʱ�ȭ
	std::fill(visited.begin(), visited.end(), false);

	// �������� ���� �� ���� ã��(Ʈ���� ����)
	dfs(end_n, 0);

	cout << answer << '\n';

	return 0;
}