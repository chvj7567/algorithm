#include <iostream>
#include <array>

using std::cin;
using std::cout;

// ��� �� ����
int row, col;
// �ٴ� ����
std::array<std::array<int, 301>, 301> sea;
// �湮 Ȯ��
std::array<std::array<int, 301>, 301> visited;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// ���� ���̴� �Լ�
int melts(int y, int x) {
	int result = 0;

	// ������ �ƴϸ� ����
	if (sea[y][x] == 0) {
		return 0;
	}
	// �����̸� 4���� �ٴ� �� ��ŭ ��´�.
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= row || nx < 0 || nx >= col) {
			continue;
		}
		if (sea[ny][nx] == 0) {
			--result;
		}
	}
	// ������ ��� �� ��ȯ
	return result;
}

bool dfs(int y, int x) {
	// ��ǥ�� ����� ����
	if (y < 0 || y >= row || x < 0 || x >= col) {
		return false;
	}
	// �̹� �湮�߰ų� �ٴٶ�� ����
	if (visited[y][x] || sea[y][x] == 0) {
		return false;
	}
	// �湮 ó��
	visited[y][x] = true;

	// ���� ��ǥ�� ���� ���
	for (int i = 0; i < 4; ++i) {
		dfs(y + dy[i], x + dx[i]);
	}

	return true;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ���� ������ ���� ����
	int cnt = 0, answer = 0;

	// ��� �� �Է�
	cin >> row >> col;

	// �ٴ� ���� �Է�
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			cin >> sea[y][x];
		}
	}

	// ù ���� Ȯ��
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			if (dfs(y, x)) {
				++cnt;
			}
		}
	}

	// ������ �̹� �� ���� �̻��̸� ����
	// �������� �� ���ܴ� ���� ����̴�.
	if (cnt >= 2) {
		return 0;
	}

	// �ʱ�ȭ
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			visited[y][x] = false;
		}
	}

	// ������ �� ���� �̻����� �и��� ������ �ݺ�
	while (cnt < 2) {
		// ������ ��� �� ����
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				visited[y][x] = melts(y, x);
			}
		}

		// ���� ���̴� �ܰ�
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				if (sea[y][x] != 0) {
					if ((sea[y][x] += visited[y][x]) < 0) {
						sea[y][x] = 0;
					}
					visited[y][x] = false;
				}
			}
		}
		// 1�� ����
		++answer;

		cnt = 0;
		// ������ ��� ���� ���� Ȯ��
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				if (dfs(y, x)) {
					++cnt;
				}
			}
		}
		if (cnt == 0) {
			// ������ �� ����������
			// 2���� �̻����� ���� �ʾ��� ��
			answer = 0;
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}