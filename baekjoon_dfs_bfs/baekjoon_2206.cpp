#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// ������ ����, ���� ����
int width, length;
// ����
std::vector<int> answer;
// ���� ����
std::array<std::string, 1001> board;
// �湮 Ȯ�� �� �� �μ� Ȯ��
std::array<std::array<std::array<int, 1001>, 1001>, 2> visited;
// ���� ��ǥ�� ��� ��ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int shortestPath(int y, int x) {
	std::queue<std::tuple<int, int, int>> q;
	// �� ���� 1�� �μ� �� �ִ� ���� ��
	// ���� ������ �Ÿ�
	visited[1][y][x] = 1;
	q.push({ 1,y,x });

	while (!q.empty()) {
		// �μ� �� �ִ� ���� ��
		int destroy = std::get<0>(q.front());
		// ���� ��ǥ
		y = std::get<1>(q.front());
		x = std::get<2>(q.front());
		q.pop();
		
		// �������� �����ߴٸ� ������ �Ÿ��� ��ȯ�ϰ� ����
		if (y == length - 1 && x == width - 1) {
			return visited[destroy][y][x];
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// ���带 ����� �ʾҴٸ�
			if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
				// �湮���� �ʾҰ� �� �� �ִ� ���̶��(���� ���ٸ�)
				// �̵� ���� 1 �߰��ϰ� ť�� push
				if (!visited[destroy][ny][nx] && board[ny][nx] == '0') {
					visited[destroy][ny][nx] = visited[destroy][y][x] + 1;
					q.push({ destroy, ny, nx });
				}
				// ���̰� ���� �μ� �� �ִ� ���¶��
				// ���� �μ� ��(�μ� �� �ִ� �� �� ����) �̵� �Ÿ� ����
				// ť�� push
				else if (destroy > 0 && board[ny][nx] == '1') {
					visited[destroy - 1][ny][nx] = visited[destroy][y][x] + 1;
					q.push({ destroy - 1, ny, nx });
				}

			}
		}
	}

	return -1;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ����, ���� ���� �Է�
	cin >> length >> width;

	// ������ ���� �Է�
	for (int i = 0; i < length; ++i) {
		std::string str;
		cin >> str;
		board[i] = str;
	}

	cout << shortestPath(0, 0) << '\n';

	return 0;
}