#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// �׸��� ����, ���� ����
int n;
// �湮 Ȯ��
std::array<std::array<bool, 101>, 101> check;

// ���� ��ǥ�� �����ǥ
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// �湮 Ȯ�� �ʱ�ȭ
void initCheck() {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			check[y][x] = false;
		}
	}
}

bool countColor(std::array<std::string, 101>& picture, int y, int x, char color) {
	// ��ǥ�� �׸��� ����� ����
	if (y < 0 || y >= n || x < 0 || x >= n) {
		return false;
	}
	// �̹� Ȯ���� ��ǥ�� ����
	if (check[y][x]) {
		return false;
	}
	// ���� �ٸ��� ����
	if (picture[y][x] != color) {
		return false;
	}
	// �湮 Ȯ�� üũ
	check[y][x] = true;
	// ���� ��ǥ�� ���
	for (int i = 0; i < 4; ++i) {
		countColor(picture, y + dy[i], x + dx[i], color);
	}

	return true;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ���ϻ����� �ƴ� ����� ���� �׸���
	// ���ϻ����� ����� ���� �׸�
	std::array<std::string, 101> normal_picture;
	std::array<std::string, 101> rg_picture;

	// �׸��� ����, ���� ����
	cin >> n;

	// �׸� ���� �Է�
	for (int y = 0; y < n; ++y) {
		std::string str;
		cin >> str;
		normal_picture[y] = str;
		rg_picture[y] = str;
	}

	// ���ϻ����� ����� ���� �׸���
	// ������ ����� ���� ���δ�.
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (rg_picture[y][x] == 'G') {
				rg_picture[y][x] = 'R';
			}
		}
	}

	// ���ϻ����� �ƴ� ����� ���� �׸��� ���� ��
	int normal_cnt = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (countColor(normal_picture, y, x, normal_picture[y][x])) {
				++normal_cnt;
			}
		}
	}

	// �湮 Ȯ�� �ʱ�ȭ
	initCheck();

	// ���ϻ����� ����� ���� �׸��� ���� ��
	int rg_cnt = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (countColor(rg_picture, y, x, rg_picture[y][x])) {
				++rg_cnt;
			}
		}
	}

	cout << normal_cnt << " " << rg_cnt << '\n';

	return 0;
}