#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// �׷���
std::vector<int> graph[1001];
// �湮 Ȯ��
std::array<bool, 1001> visited;

bool connect(int v) {
	bool check = true;

	// ������ ���� ������ ���
	// �ϳ��� ���� ��� �̹Ƿ� true ��ȯ
	if (graph[v].size() == 0) {
		return true;
	}

	// �������� ����� ���� ��
	// �湮���� ���� ���� Ȯ��
	for (int i = 0; i < graph[v].size(); ++i) {
		int tmp = graph[v][i];
		if (!visited[tmp]) {
			check = false;
		}
	}

	// ��� �湮�ߴٸ� �̹� ī������ �ƴ�.
	if (check) {
		return false;
	}

	// �湮 Ȯ�� üũ
	visited[v] = true;

	// �湮���� ���� ������ Ȯ��
	for (int i = 0; i < graph[v].size(); ++i) {
		int next = graph[v][i];
		if (!visited[next]) {
			visited[next] = true;
			connect(next);
		}
	}

	return true;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ ��, ������ ��
	int n, m;
	// ����
	int cnt = 0;

	// ������ ��, ������ �� �Է�
	cin >> n >> m;

	// ���� �Է�
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		// �����
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// �������� ����
	for (int i = 0; i < n; ++i) {
		std::sort(graph[i].begin(), graph[i].end());
	}

	// ���� ��� ã��
	for (int i = 1; i <= n; ++i) {
		if (connect(i)) {
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}