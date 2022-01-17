#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// �������� ����, ���� ���̿�
// ���簢���� ���� �� ������ ����
int width, length, number, cnt = 0;
// ������ ����
std::array<std::array<bool, 101>, 101> board;
// �湮 Ȯ��
std::array<std::array<bool, 101>, 101> visited;
// ���� ��ǥ�� �����ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int area(int y, int x) {
	// ��ǥ�� �� ���̸� ����� ����
	if (y < 0 || y >= length || x < 0 || x >= width) {
		return 0;
	}
	// �̹� �湮�߰ų� �� ��ǥ�� �ƴ϶�� ����
	if (visited[y][x] || board[y][x] == 1) {
		return 0;
	}
	// �湮 ó�� �� ī����
	visited[y][x] = true;
	++cnt;
	// ���� ��ǥ�� ���� ���
	for (int i = 0; i < 4; ++i) {
		area(y + dy[i], x + dx[i]);
	}

	return cnt;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �� ������ ����, ����, ���簢���� �� �Է�
	cin >> length >> width >> number;

	// ���簢���� ��ǥ �Է�
	for (int i = 0; i < number; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		// ��ǥ�� ���� �����̿� ǥ��
		for (int y = b; y < d; ++y) {
			for (int x = a; x < c; ++x) {
				board[y][x] = 1;
			}
		}
	}

	// �� ������ �� ���ϱ�
	std::vector<int> answer;
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			// ������ ���� 1�̻� �϶��� ��� ��
			// ī���� �ʱ�ȭ(������ ������ ����)
			if (area(y, x)) {
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// �������� ����
	std::sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i : answer) {
		cout << i << ' ';
	}

	return 0;
}