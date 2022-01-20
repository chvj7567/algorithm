#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;

// ������ ����, ���� ����
int width, length;
// ���� ����
std::array<std::array<int, 101>, 101> board;
// ���� ġ��
std::array<std::array<bool, 101>, 101> melt_check;
// �ܺ� ���� Ȯ��
std::array<std::array<bool, 101>, 101> visited;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// �ܺ� ���� Ȯ���ϴ� dfs
void dfs(int y, int x) {
	if (y < 0 || y >= length || x < 0 || x >= width) {
		return;
	}

	if (visited[y][x] || board[y][x] == 1) {
		return;
	}

	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		dfs(y + dy[i], x + dx[i]);
	}
}

void melts(int y, int x) {
	// ġ� �ƴϸ� ����
	if (board[y][x] == 0) {
		return;
	}

	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// �������� �ܺ� �����̸�
		if (board[ny][nx] == 0 && visited[ny][nx]) {
			++cnt;
		}
	}

	// �ܺ� ���Ⱑ �� �� �̻� ��������� üũ
	if (cnt >= 2) {
		melt_check[y][x] = true;
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ����, ���� ���� �Է�
	cin >> length >> width;

	// ġ���� ��
	int cheese = 0;
	// ġ� �ִ��� üũ
	bool nothing = true;
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			// ġ� �ִٸ�
			if (board[y][x] == 1) {
				nothing = false;
				++cheese;
			}
		}
	}

	// ġ� ���ٸ� 0 ��� �� ����
	if (nothing) {
		cout << 0 << '\n';
		return 0;
	}

	// �ܺ� ���� Ȯ��
	dfs(0, 0);

	// ġ� �� ��µ� �ɸ��� �ð�
	int hour = 0;

	while (1) {
		// 1�ð�
		++hour;

		// ���� ġ�� Ȯ��
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				melts(y, x);
			}
		}

		// ġ�� ���� �� �ش� �ڸ�����
		// �ٽ� �ܺ� ���� Ȯ��
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (melt_check[y][x]) {
					board[y][x] = 0;
					dfs(y, x);
					--cheese;
					melt_check[y][x] = false;
				}
			}
		}

		// ġ� ���ٸ� �ݺ��� ����
		if (cheese == 0) {
			break;
		}
	}

	cout << hour << '\n';

	return 0;
}