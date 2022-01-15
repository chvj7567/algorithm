#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// ������ ����, ���� ����
int n;
// ������ ���� ����
std::array<std::array<int, 101>, 101> area;
// ���� ���� Ȯ��
std::array<std::array<bool, 101>, 101> safe;
// ������ Ȯ���� ��� ��ǥ
std::array<int, 4> by = { -1,0,1,0 };
std::array<int, 4> bx = { 0,1,0,-1 };

bool safeArea(int cur_x, int cur_y, int rain) {
	// ��ǥ�� Ȯ���� ���¸� ����
	if (safe[cur_y][cur_x]) {
		return false;
	}
	// ��ǥ�� ħ�������̸� ����
	if (area[cur_y][cur_x] <= rain) {
		return false;
	}

	std::queue<std::pair<int, int>> q;
	safe[cur_y][cur_x] = true;
	q.push({ cur_y,cur_x });

	while (!q.empty()) {
		// ���� ��ǥ
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();
		// ���� ��ǥ Ȯ��
		for (int i = 0; i < 4; ++i) {
			int ny = cur_y + by[i];
			int nx = cur_x + bx[i];
			// ��ǥ�� ������ ����� ������
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// ��ǥ�� Ȯ������ �ʾҰ� ���������̸�
				if (!safe[ny][nx] && area[ny][nx] > rain) {
					safe[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}

	return true;
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ ����, ���� ���� �Է�
	cin >> n;

	// �������� ������ ������ ��ġ�� �ּ�, �ִ�ġ
	int minRain = 101;
	int maxRain = 0;
	
	// �� ������ ���� �Է�
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> area[i][j];
			minRain = std::min(minRain, area[i][j]);
			maxRain = std::max(maxRain, area[i][j]);
		}
	}

	// ��� ������ ���� �������� Ȯ��
	int same = area[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (area[i][j] != same) {
				same = -1;
			}
		}
	}

	// ��� ������ ���� ���̶��
	// �ִ� ���������� ���� 1�̹Ƿ�
	// 1�� ����ϰ� ����
	if (same != -1) {
		cout << 1 << endl;
		return 0;
	}

	// ����
	int answer = 0;
	// ������ �ݺ�
	for (int k = minRain; k < maxRain; ++k) {
		// �� ���������� ���� ���� ����
		int cnt = 0;
		// �������� �ٲ𶧸��� �ʱ�ȭ
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				safe[i][j] = false;
			}
		}
		// �� ���������� ���� ���� ���� üũ
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (safeArea(i, j, k)) {
					++cnt;
				}
			}
		}
		// ���� ���� ������ ���� ���� ��� ����
		answer = std::max(answer, cnt);
	}

	cout << answer << endl;

	return 0;
}