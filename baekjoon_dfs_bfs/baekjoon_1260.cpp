#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// ���
std::vector<int> node[1001];
// �湮 Ȯ��
std::array<bool, 1001> visited;

void dfs(int v) {
	// �ش� ��尡 �湮�ߴٸ� ����
	if (visited[v]) {
		return;
	}

	// �湮���� �ʾҴٸ� �湮 ó�� �� ���
	visited[v] = true;
	cout << v << " ";

	// ���� ���� ��ο��� dfs ����
	for (int i = 0; i < node[v].size(); i++) {
		dfs(node[v][i]);
	}

}

void bfs(int v) {
	std::queue<int> q;

	// Ž�� ���� ��� �湮 ó�� �� ���
	visited[v] = true;
	cout << v << " ";

	// ť push
	q.push(v);

	// ť�� �� ������
	while (!q.empty()) {
		// ť�� �ֻ�� ��� �� ����
		int num = q.front();
		// ť pop
		q.pop();

		// ���� ���� ���� �湮
		for (int i = 0; i < node[num].size(); ++i) {
			int value = node[num][i];
			// �湮 ���� �ʾҴٸ�
			// �湮 ó��, ��� �� ť push
			if (!visited[value]) {
				visited[value] = true;
				cout << value << " ";
				q.push(value);
			}
		}
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ���� ����, ���� ����, Ž�� ���� ��ȣ
	int n, m, v;

	// ���� ����, ���� ����, Ž�� ���� ��ȣ �Է�
	cin >> n >> m >> v;

	// ���� �Է�
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		// �����
		node[a].push_back(b);
		node[b].push_back(a);
	}

	// �������� ����
	for (int i = 1; i <= n; ++i) {
		std::sort(node[i].begin(), node[i].end());
	}

	dfs(v);

	cout << '\n';

	// �湮 Ȯ�� �ʱ�ȭ
	for (int i = 1; i <= n; ++i) {
		visited[i] = false;
	}

	bfs(v);

	return 0;
}