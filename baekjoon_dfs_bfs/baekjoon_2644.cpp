#include <iostream>
#include <vector>
#include <array>
#include <queue>

using std::cin;
using std::cout;

// ��� ���� ���� ��
int n, v;
// �̼��� ��Ÿ�� �� ���
int p1, p2;
// �� ������� ���� �׷���
std::array<std::vector<int>, 101> graph;
// ���� Ȯ��
std::array<int, 101> check;

int bfs(int v) {
	std::queue<int> q;
	// ���� Ȯ�� üũ / �̼� Ȯ��
	check[v] = 1;
	q.push(v);

	while (!q.empty()) {
		int cur_n = q.front();
		q.pop();

		for (int i = 0; i < graph[cur_n].size(); ++i) {
			int next_n = graph[cur_n][i];
			// ���踦 Ȯ������ �ʾҴٸ�
			if (!check[next_n]) {
				// �̼��� ��Ÿ�� ����� ã�Ҵٸ�
				// ������ ����� �̼��� ��ȯ
				// 1�� �߰��ϱ� ���̹Ƿ� -1�� ���ص� �ȴ�.
				if (next_n == p2) {
					return check[cur_n];
				}
				check[next_n] = check[cur_n] + 1;
				q.push(next_n);
			}
		}
	}

	// �̼��� ��Ÿ���� ���ϸ� -1 ��ȯ
	return -1;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��� �� �Է�
	cin >> n;
	// �̼��� ��Ÿ�� �� ��� �Է�
	cin >> p1 >> p2;
	// ���� �� �Է�
	cin >> v;

	// ���� �Է�
	for (int i = 0; i < v; ++i) {
		int a, b;
		cin >> a >> b;
		// �����
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(p1) << '\n';

	return 0;
}