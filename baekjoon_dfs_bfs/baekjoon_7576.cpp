#include <iostream>
#include <queue>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ������ ���α���, ���� ����
int width, height;
// �ڽ� ���� �丶�� ����
std::array<std::array<int, 1001>, 1001> box;
// �;����� Ȯ��
std::array<std::array<int, 1001>, 1001> ripe;

// �����¿� �����ǥ(��-��-��-�� ��)
std::array<int, 4> by = { -1,0,1,0 };
std::array<int, 4> bx = { 0,1,0,-1 };

// ��� �丶�䰡 �־����� Ȯ��
bool check() {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (box[y][x] == 0) {
				return false;
			}
		}
	}

	return true;
}

int minDate() {
	std::queue<std::pair<int, int>> q;

	// ���� �丶���� ��ǥ ť push �� üũ
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (box[i][j] == 1) {
				q.push({ i,j });
				ripe[i][j] = 0;
			}
		}
	}

	// ��� �丶�䰡 �־��ٸ� ����
	if (check()) {
		return 0;
	}

	// �丶�䰡 ��� �ͱ������ �Ⱓ
	int cnt = 0;

	while (!q.empty()) {
		// ��ǥ
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// �����¿� ��ǥ Ȯ��
		for (int i = 0; i < 4; ++i) {
			int ny = y + by[i];
			int nx = x + bx[i];
			// ��ǥ�� ���ڸ� ����� ������
			if (!(ny < 0 || ny >= height || nx < 0 || nx >= width)) {
				// �;����� Ȯ���� ���Ͽ��� �� ���� �丶����
				if (!ripe[ny][nx] && box[ny][nx] == 0) {
					// �丶�信 ���������� �ɸ� �ð��� �����ϰ�
					// ������ �ð��� cnt�� ���
					cnt = ripe[ny][nx] = ripe[y][x] + 1;
					box[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}

	// �丶�䰡 ��� �;��ٸ� cnt ��ȯ
	if (check()) {
		return cnt;
	}
	// �丶�䰡 ��� �� �;��ٸ� ��� �ʹ°� �Ұ����ϹǷ� - 1 ��ȯ
	else {
		return -1;
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ ���α���, ���α��� �Է�
	cin >> width >> height;

	// ���� ���� �丶�� ���� �Է�
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> box[y][x];
		}
	}

	cout << minDate() << '\n';

	return 0;
}