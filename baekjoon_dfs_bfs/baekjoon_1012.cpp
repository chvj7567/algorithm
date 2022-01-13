#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ���� ����, ���� ����, ������ ��
int width, height, number;
// ���� ����
std::array<std::array<int, 51>, 51> field;
// �� Ȯ��
std::array<std::array<bool, 51>, 51> ok;

bool minWorm(int x, int y) {
	// ���� ����� ����
	if (x < 0 || x >= width || y < 0 || y >= height) {
		return false;
	}

	// ���߰� ������ ����
	if (field[x][y] == 0) {
		return false;
	}

	// ���߰� �ִµ� Ȯ������ ���� ���̸� Ȯ��
	// ���� �����¿�� Ȯ��
	if (!ok[x][y]) {
		ok[x][y] = true;
		minWorm(x + 1, y);
		minWorm(x - 1, y);
		minWorm(x, y + 1);
		minWorm(x, y - 1);
		return true;
	}

	return false;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �׽�Ʈ ���̽� ���� �� ����
	int test_case, cnt = 0;
	// �����
	std::vector<int> answer;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
	while (test_case > 0) {
		// ���� ����, ����, ���� �� �Է�
		cin >> width >> height >> number;

		// ���߰� �ִ� �� �Է�
		for (int i = 0; i < number; ++i) {
			int a, b;
			cin >> a >> b;
			field[a][b] = 1;
		}

		// ����� ������ ������ ����
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				if (minWorm(x, y)) {
					++cnt;
				}
			}
		}

		answer.push_back(cnt);

		// ���� �׽�Ʈ ���̽��� ���� �ʱ�ȭ
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				field[x][y] = 0;
				ok[x][y] = false;
			}
		}
		cnt = 0;
		--test_case;
	}

	for (int cnt : answer) {
		cout << cnt << '\n';
	}

	return 0;
}