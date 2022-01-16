#include <iostream>
#include <array>
#include <queue>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;

// ������ ����, ����, ���� ����
int width, length, height;
// �ڽ��� ����
std::array<std::array<std::array<int, 101>, 101>, 101> box;
// �ڽ� Ȯ��
std::array<std::array<std::array<int, 101>, 101>, 101> check;

// ���� ��ǥ�� �����ǥ
std::array<int, 6> dz{ 1,-1,0,0,0,0 };
std::array<int, 6> dy{ 0,0,-1,0,1,0 };
std::array<int, 6> dx{ 0,0,0,1,0,-1 };

int dateRipe() {
	std::queue<std::tuple<int, int, int>> q;

	bool end_ripe = true;
	bool no_ripe = true;
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (box[z][y][x] == 1) {
					check[z][y][x] = 1;
					q.push({ z,y,x });
				}
				if (box[z][y][x] == 0) {
					end_ripe = false;
				}
				if (box[z][y][x] != 0) {
					no_ripe = false;
				}
			}
		}
	}
	// �丶�䰡 �̹� �� �;��ٸ� 0 ��ȯ
	if (end_ripe) {
		return 0;
	}
	// ���� �丶�䰡 ���ٸ� -1 ��ȯ
	if (no_ripe) {
		return -1;
	}

	int cnt = 0;
	while (!q.empty()) {
		// ���� ��ǥ
		int z = std::get<0>(q.front());
		int y = std::get<1>(q.front());
		int x = std::get<2>(q.front());
		q.pop();

		// ���� ��ǥ
		for (int i = 0; i < 6; ++i) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			// ��ǥ�� ���ڸ� ����� �ʾҴٸ�
			if (!(nz < 0 || nz >= height || ny < 0 || ny >= length || nx < 0 || nx >= width)) {
				// Ȯ������ ���� ��ǥ�̰� ���� ���� �丶�䰡 �ִٸ�
				if (!check[nz][ny][nx] && box[nz][ny][nx] == 0) {
					cnt = check[nz][ny][nx] = check[z][y][x] + 1;
					box[nz][ny][nx] = 1;
					q.push({ nz,ny,nx });
				}
			}
		}
	}

	// �丶�䰡 �� �;����� Ȯ��
	bool all_ripe = true;
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (box[z][y][x] == 0) {
					all_ripe = false;
				}
			}
		}
	}

	// �丶�䰡 ���;��ٸ� ó���� ���� �丶�� Ȯ���� ����
	// 1�� �ʱ�ȭ �����Ƿ� cnt - 1 ��ȯ
	if (all_ripe) {
		return cnt - 1;
	}
	// �丶�䰡 �� ���;��ٸ� �� �Ͱ� �� �� �����Ƿ� -1 ��ȯ
	else {
		return -1;
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ����, ����, ���� �Է�
	cin >> width >> length >> height;

	// ������ ���� �Է�
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				cin >> box[z][y][x];
			}
		}
	}

	cout << dateRipe() << '\n';

	return 0;
}