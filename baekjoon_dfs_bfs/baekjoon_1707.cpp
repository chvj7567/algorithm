#include <iostream>
#include <vector>
#include <array>
#include <queue>

using std::cin;
using std::cout;

// ������ ������ ��
int v, e;
// �׷��� ����
std::array<std::vector<int>, 200001> graph;
// �湮 Ȯ��
std::array<int, 20001> visited;

// ����� ����
// WHITE = 0(ĥ���� ����)
// RED = 1
// BLACK = 2
enum Color {
	WHITE,
	RED,
	BLACK
};

bool bfs(int n) {
	std::queue<std::pair<int, int>> q;
	// ������ ��ȣ�� ���� ť�� push
	q.push({ n, visited[n] });

	// ť�� �� ������
	while (!q.empty()) {
		// ���� ���� ��ȣ�� �� ���� �� ť pop
		int cur = q.front().first;
		int color = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			// ���� ����
			int next = graph[cur][i];
			// ���� ������ ���� ����ٸ�
			if (visited[next] == WHITE) {
				// �������̸� ���������� ĥ�Ѵ�.
				if (color == BLACK) {
					visited[next] = RED;
				}
				// �������̸� ���������� ĥ�Ѵ�.
				else {
					visited[next] = BLACK;
				}
				q.push({ next, visited[next] });
			}
			// ���� ������ ���� ĥ���� �ִٸ�
			else {
				// ���� ���ٸ� �̺� �׷��� ���� ó��
				if (visited[next] == color) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �׽�Ʈ ���̽� ��
	int test_case;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// ����
	std::vector<bool> answer;

	while (test_case > 0) {
		// ���� ���� ���� �� �Է�
		cin >> v >> e;

		// �׷��� �Է�
		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			// �����
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		// ���� ���� �� ���� ����
		visited[1] = RED;

		// �̺� �׷��� �Ǵ�
		bool result = true;
		for (int i = 1; i <= v; ++i) {
			if (!bfs(i)) {
				result = false;
			}
		}
		answer.push_back(result);

		// ���� �׽�Ʈ ���̽��� ���� �ʱ�ȭ
		for (int i = 1; i <= v; ++i) {
			visited[i] = false;
			graph[i].clear();
		}

		--test_case;
	}

	for (auto a : answer) {
		if (a) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}