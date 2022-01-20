#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ���� ũ��� ����
int n, answer = 0;
// ���� ����
std::array<std::array<int, 501>, 501> board;
// �湮 Ȯ�� �� �̵� ĭ �� ����
std::array<std::array<int, 501>, 501> visited;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int dfs(int y, int x) {
	// �̹� �湮�ߴٸ� ���� �� ��ȯ
	if (visited[y][x] != 0) {
		return visited[y][x];
	}

	// 1ĭ �̵� Ȯ��
	visited[y][x] = 1;

	// ���� ��ǥ�� �̵�
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// ���� ����� �ʾҴٸ�
		if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
			// ���� ĭ�� �볪���� �� ���ٸ�
			if (board[y][x] < board[ny][nx]) {
				// �� ĭ���� �ִ� �̵� �� ����
				visited[y][x] = std::max(visited[y][x], dfs(ny, nx) + 1);
			}
		}
	}

	return visited[y][x];
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ���� ũ�� �Է�
	cin >> n;

	// ���� ���� �Է�
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> board[y][x];
		}
	}

	// �� ĭ���� ���� ���� �̵��� �� �ִ� ĭ ����
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			answer = std::max(answer, dfs(y, x));
		}
	}

	cout << answer << '\n';

	return 0;
}