#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// ������ ���α���, ���α���
int w, h;
// ������ ����
std::array<std::array<int, 51>, 51> board;
// Ȯ�� ����
std::array<std::array<bool, 51>, 51> check;
// ���� ��ǥ�� ��� ��ǥ(���� ��ܺ��� �ð� ���� ��)
std::array<int, 8> by = { -1,-1,-1,0,0,1,1,1 };
std::array<int, 8> bx = { -1,0,1,-1,1,-1,0,1 };

bool dfs(int y, int x) {
	// ��ǥ�� ������ ����� ����
	if (x < 0 || x >= w || y < 0 || y >= h) {
		return false;
	}

	// ��ǥ�� �ٴٸ� ����
	if (board[y][x] == 0) {
		return false;
	}

	// Ȯ���� ���� ��ǥ�̸� Ȯ��
	if (!check[y][x]) {
		check[y][x] = true;
		// ���� ��ǥ�� Ȯ��
		for (int i = 0; i < 8; ++i) {
			dfs(y + by[i], x + bx[i]);
		}
		return true;
	}

	return false;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ����
	std::vector<int> answer;

	// ���� �ݺ�
	while (1) {
		// ������ ���α���, ���α��� �Է�
		cin >> w >> h;

		// 0 0 �� �ԷµǸ� ����
		if (!w && !h) {
			break;
		}

		// ������ ���� �Է�
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				cin >> board[y][x];
			}
		}

		// ���� ����
		int cnt = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (dfs(y, x)) {
					++cnt;
				}
			}
		}

		// ���� ���̽��� ���� �ʱ�ȭ
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				board[y][x] = 0;
				check[y][x] = false;
			}
		}
		// ���� ���� ����
		answer.push_back(cnt);
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}