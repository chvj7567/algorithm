#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ������ ����, ���� ���̿�
// �� ��θ��� �� �� �ִ� �Ÿ���
// �ִ�� �� �� �ִ� �Ÿ�
int width, length, cnt = 0, answer = 0;
// ������ ����
std::array<std::string, 21> board;
// �� ���ĺ� Ȯ��
std::array<bool, 26> alpha;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

void ableMove(int y, int x) {
	// cnt�� answer �� ���� ���� �������� �ٲ۴�.
	answer = std::max(answer, cnt);
	// �ش� ���ĺ� Ȯ�� üũ
	alpha[board[y][x] - 'A'] = true;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// ��ǥ�� ���� ���̶��
		if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
			// �ش� ���ĺ��� Ȯ�ε��� ���� ���¶��
			if (!alpha[board[ny][nx] - 'A']) {
				alpha[board[ny][nx] - 'A'] = true;
				++cnt;
				ableMove(ny, nx);
				alpha[board[ny][nx] - 'A'] = false;
				--cnt;
			}
		}
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ����, ���� ���� �Է�
	cin >> length >> width;

	// ���� ���� �Է�
	for (int i = 0; i < length; ++i) {
		std::string str;
		cin >> str;
		board[i] = str;
	}

	ableMove(0, 0);

	cout << answer + 1 << '\n';

	return 0;
}