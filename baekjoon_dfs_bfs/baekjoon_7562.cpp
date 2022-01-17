#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// ü������ ����
int n;
// ���� ��ǥ�� ��ǥ ��ǥ
int start_x, start_y, finish_x, finish_y;
// ü���� / �湮 Ȯ��
std::array<std::array<int, 301>, 301> visited;
// ���� ��ǥ�� �����ǥ
std::array<int, 8> dy{ -1,-2,-2,-1,1,2,2,1 };
std::array<int, 8> dx{ -2,-1,1,2,2,1,-1,-2 };

int move(int y, int x) {
	std::queue<std::pair<int, int>> q;
	// �湮 Ȯ�� �� �̵� �� ����
	// 0�� false�̹Ƿ� 1 ���� ��
	// �������� -1
	visited[y][x] = 1;
	q.push({ y,x });

	int cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// ü������ ����� �ʾ�����
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// �湮���� �ʾ�����
				if (!visited[ny][nx]) {
					// �̵� �� 1 �߰� �� ����
					cnt = visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	// ó�� ��ǥ���� �湮 Ȯ���� ���� 1�� �־����Ƿ� -1 �� ��ȯ
	return visited[finish_y][finish_x] - 1;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �׽�Ʈ ���̽� ��
	int test_case;
	// ����
	std::vector<int> answer;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
	while (test_case > 0) {
		// ü������ ���� �Է�
		cin >> n;
		// ���� ��ǥ�� ��ǥ ��ǥ �Է�
		cin >> start_x >> start_y;
		cin >> finish_x >> finish_y;

		// ���� push
		answer.push_back(move(start_y, start_x));

		// ü���� / �湮 Ȯ�� �ʱ�ȭ
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				visited[y][x] = 0;
			}
		}
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// ü������ ����
int n;
// ���� ��ǥ�� ��ǥ ��ǥ
int start_x, start_y, finish_x, finish_y;
// ü���� / �湮 Ȯ��
std::array<std::array<int, 301>, 301> visited;
// ���� ��ǥ�� �����ǥ
std::array<int, 8> dy{ -1,-2,-2,-1,1,2,2,1 };
std::array<int, 8> dx{ -2,-1,1,2,2,1,-1,-2 };

int move(int y, int x) {
	std::queue<std::pair<int, int>> q;
	// �湮 Ȯ�� �� �̵� �� ����
	// 0�� false�̹Ƿ� 1 ���� ��
	// �������� -1
	visited[y][x] = 1;
	q.push({ y,x });

	int cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// ü������ ����� �ʾ�����
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// �湮���� �ʾ�����
				if (!visited[ny][nx]) {
					// �̵� �� 1 �߰� �� ����
					cnt = visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	// ó�� ��ǥ���� �湮 Ȯ���� ���� 1�� �־����Ƿ� -1 �� ��ȯ
	return visited[finish_y][finish_x] - 1;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �׽�Ʈ ���̽� ��
	int test_case;
	// ����
	std::vector<int> answer;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
	while (test_case > 0) {
		// ü������ ���� �Է�
		cin >> n;
		// ���� ��ǥ�� ��ǥ ��ǥ �Է�
		cin >> start_x >> start_y;
		cin >> finish_x >> finish_y;

		// ���� push
		answer.push_back(move(start_y, start_x));

		// ü���� / �湮 Ȯ�� �ʱ�ȭ
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				visited[y][x] = 0;
			}
		}
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}