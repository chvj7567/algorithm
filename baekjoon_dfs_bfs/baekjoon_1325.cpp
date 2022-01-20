#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// ��Ʈ��ũ ����
std::array<std::vector<int>, 10001> network;
// �湮 Ȯ��
std::array<int, 10001> visited;

// ����� ��ǻ�� ��
int cnt = 1;

void bfs(int node) {
	// �湮 ó�� �� ť�� push
	std::queue<int> q;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		// ���� ��ǻ�� ��ġ ���� �� ť pop
		node = q.front();
		q.pop();

		// ����� �ٸ� ��ǻ�ͷ� �̵�
		for (int i : network[node]) {
			// �湮�� ���°� �ƴ϶��
			// �湮 �� ī����, ť push
			if (!visited[i]) {
				visited[i] = true;
				++cnt;
				q.push(i);
			}
		}
	}
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��ǻ�� ���� ��Ʈ��ũ ��
	int n, m;

	// ��ǻ�� ���� ��Ʈ��ũ �� �Է�
	cin >> n >> m;

	// ��Ʈ��ũ ���� �Է�
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		network[b].push_back(a);
	}

	// ����
	std::vector<int> answer;
	// �� ��ǻ�͸��� ���ᰡ���� ��ǻ�� ���� ī�����ϰ�
	// �� ���� ���� �� ���� ���̽��� ���� �ʱ�ȭ �ݺ�
	for (int i = 1; i <= n; ++i) {
		bfs(i);
		answer.push_back(cnt);
		std::fill(visited.begin(), visited.end(), false);
		cnt = 1;
	}

	// ���� ������ ��ǻ���� �ִ� ����
	int max_num = 0;
	for (int i : answer) {
		max_num = std::max(max_num, i);
	}

	// ���� ������ �ִ񰪰� ���� ��ǻ�͸� ������������ ���
	// ����� ���� �� ��ǻ���� ��ȣ - 1�� �����Ƿ� + 1�� ���ش�.
	for (int i = 0; i < answer.size(); ++i) {
		if (max_num == answer[i]) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}