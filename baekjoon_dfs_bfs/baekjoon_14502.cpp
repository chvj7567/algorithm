#include <iostream>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// �������� ���α���, ���α���, ����
int height, width, answer = 0;
// �������� ����
std::array<std::array<int, 9>, 9> board;
// �������� ���� ����
std::array<std::array<int, 9>, 9> copy_board;
// ���̷����� ���� ��� ��ǥ
std::array<int, 4> fy{ -1,0,1,0 };
std::array<int, 4> fx{ 0,1,0,-1 };

void maxSafe() {
	std::queue<std::pair<int, int>> q;

	// �� 3���� ���� �������� ���� ����
	std::copy(board.begin(), board.end(), copy_board.begin());

	// ���̷����� �ִ� ��ǥ ť�� push
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (copy_board[y][x] == 2) {
				q.push({ y,x });
			}
		}
	}

	while (!q.empty()) {
		// ���̷����� �ִ� ��ǥ
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = ty + fy[i];
			int nx = tx + fx[i];
			// ��ǥ�� �����Ҹ� ����� �ʾ�����
			if (!(ny < 0 || ny >= height || nx < 0 || nx >= width)) {
				// �� �����̸� ���̷��� ħ��
				if (copy_board[ny][nx] == 0) {
					copy_board[ny][nx] = 2;
					q.push({ ny,nx });
				}
			}
		}
	}
	// ���� ������ ��
	int cnt = 0;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (copy_board[y][x] == 0) {
				++cnt;
			}
		}
	}

	// ���� ������ ���� ���� ���� ��츦 ����
	answer = std::max(answer, cnt);
}

void wall(int cnt) {
	// �� 3���� �������� ���̷��� �ùķ��̼�
	if (cnt == 3) {
		maxSafe();
		return;
	}
	// �� 3���� ����� ��� ���
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (board[y][x] == 0) {
				board[y][x] = 1;
				++cnt;
				wall(cnt);
				board[y][x] = 0;
				--cnt;
			}
		}
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �������� ���α���, ���α��� �Է�
	cin >> height >> width;

	// �������� ���� �Է�(���纻���� �Է�)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			copy_board[y][x] = board[y][x];
		}
	}

	wall(0);

	cout << answer << endl;

	return 0;
}