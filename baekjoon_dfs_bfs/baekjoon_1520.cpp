#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ������ ����, ���� ����
int width, length;
// ���� ����
std::array<std::array<int, 501>, 501> board;
// �湮 Ȯ��
std::array<std::array<int, 501>, 501> visited;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int dfs(int y, int x) {
	// ��ǥ�� ���������� ����
	if (y == length - 1 && x == width - 1) {
		return 1;
	}
	// �̹� �湮�� ���̶�� ���� ��� ��ȯ
	if (visited[y][x] != -1) {
		return visited[y][x];
	}

	// �湮 Ȯ��
	visited[y][x] = 0;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// ������ ����� �ʾ�����
		if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
			// ���� ��ǥ�� ���� ���� ��ǥ�� ������ ������
			if (board[y][x] > board[ny][nx]) {
				visited[y][x] += dfs(ny, nx);
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

	// ������ ����, ���� ���� �Է�
	cin >> length >> width;

	// ���� ���� �Է�
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
		}
	}

	// �ִ� ��ΰ� �ƴ� ����� �� �̹Ƿ�
	// -1�� �湮 ��Ȯ��, 0�� �湮 Ȯ������ �Ͽ�
	// ī���� �� ������ ���� 1�� ��ȯ��(0�� ���ص� 0)
	// -1�� �ʱ�ȭ
	for (int i = 0; i < 501; ++i) {
		std::fill(visited[i].begin(), visited[i].end(), -1);
	}

	cout << dfs(0, 0) << '\n';

	return 0;
}