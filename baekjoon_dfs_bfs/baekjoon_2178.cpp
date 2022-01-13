#include <iostream>
#include <string>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// ���� ����, ���� ����
int n, m;
// �̷���
std::array<std::array<int, 101>, 101> board;
// �湮 Ȯ��
std::array<std::array<int, 101>, 101> visited;
// �����¿� �����ǥ(��-��-��-�� ��)
int by[4] = { -1,0,1,0 };
int bx[4] = { 0,1,0,-1 };

int bfs(int x, int y) {
	// ť�� �湮 ��� �� ����(����� �̵��Ÿ�)
	std::queue<std::pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {
		// �湮�� ����� ��ǥ �ް� ����
		y = q.front().first;
		x = q.front().second;
		q.pop();

		// ��ǥ ������ ������ �� �ݺ��� ����
		if (y == n - 1 && x == m - 1) {
			break;
		}

		// �����¿� ��ǥ�� ���켭 �� �� �ִ°� Ž��
		for (int i = 0; i < 4; ++i) {
			int ny = y + by[i];
			int nx = x + bx[i];
			// �̷θ� ����� ��ǥ�� �ƴ϶��
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= m)) {
				// �湮���� ���� ���̰� �� �� �ִ� ���̸�(1 �̸�)
				if (!visited[ny][nx] && board[ny][nx] == 1) {
					// �̵� �Ÿ��� + 1 ���� �� ť�� ����
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}

	// ���� ��ǥ�� �� �̵��Ÿ��� ����Ǿ� �ִ�.
	return visited[n - 1][m - 1];
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ���� ����, ���� ���� �Է�
	cin >> n >> m;
	
	// �̷��� ����
	for (int y = 0; y < n; ++y) {
		std::string str;
		cin >> str;
		for (int x = 0; x < m; ++x) {
			board[y][x] = str[x] - '0';
		}
	}

	cout << bfs(0, 0) << '\n';

	return 0;
}