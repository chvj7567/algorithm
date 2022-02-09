#include <iostream>
#include <string>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 10�� n�� ���� n
int n;
// �ȳ����� ����
std::array<std::string, 5> board = {};
// �ش� �ε����� ���ڰ� �������� ����
std::array<std::array<bool, 10>, 10> isAble = {};
// �� �ڸ����� ������ ���ڵ�
std::array<std::vector<int>, 10> isAbleNumber = {};

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// n �Է�
	cin >> n;

	// �ȳ����� ���� �Է�
	for (int i = 0; i < 5; ++i) {
		cin >> board[i];
	}

	// �˻� �� �ش� ���ڵ��� �� �����ϴٰ� �Ǵ�
	for (int i = 0; i < n; ++i) {
		std::fill(isAble[i].begin(), isAble[i].end(), true);
	}

	// �� ���ڵ��� ���� ���� �κ���(���� ����)
	// �ȳ����� ���¿��� ���� �����ִٸ� �ش� ���ڴ� �Ұ��� ó��
	for (int i = 0, j = 0; i <= 4 * n - 1; i += 4, ++j) {
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 3; ++x) {
				if (board[y][i + x] == '#') {
					if (x == 1 && (y == 1 || y == 2 || y == 3)) {
						isAble[j][0] = false;
					}
					if (x != 2) {
						isAble[j][1] = false;
					}
					if ((y == 1 && x != 2) || (y == 3 && x != 0)) {
						isAble[j][2] = false;
					}
					if ((y == 1 || y == 3) && x != 2) {
						isAble[j][3] = false;
					}
					if ((x == 0 && (y == 3 || y == 4)) || (x == 1 && y != 2)) {
						isAble[j][4] = false;
					}
					if ((y == 1 && x != 0) || (y == 3 && x != 2)) {
						isAble[j][5] = false;
					}
					if ((y == 1 && x != 0) || (y == 3 && x == 1)) {
						isAble[j][6] = false;
					}
					if (x != 2 && y != 0) {
						isAble[j][7] = false;
					}
					if (x == 1 && (y == 1 || y == 3)) {
						isAble[j][8] = false;
					}
					if ((y == 1 && x == 1) || (y == 3 && x != 2)) {
						isAble[j][9] = false;
					}
				}
			}
		}
	}

	// �� �ڸ����� ������ ���ڵ� ����
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (isAble[i][j]) {
				isAbleNumber[i].push_back(j);
			}
		}
	}

	// �ϳ��� �ڸ��� ��� ���ڰ� �Ұ����ϴٸ�
	// ��ü ���ڴ� ���ǹ����� Ȯ��
	bool check = false;
	for (int i = 0; i < n; ++i) {
		if (isAbleNumber[i].empty()) {
			check = true;
		}
	}

	// ���ڰ� �Ұ����ϴٸ� -1 ���
	if (check) {
		cout << -1 << '\n';
		return 0;
	}

	// ����
	double answer = 0.0;
	for (int i = n - 1, digit = 1; i >= 0; --i, digit *= 10) {
		long long sum = 0;
		int cnt = 0;
		// �ش� �ڸ����� ��� ���ڵ��� ��
		for (auto a : isAbleNumber[i]) {
			sum += a;
			++cnt;
		}
		// �ش� �ڸ����� �������� ������ ���Ѵ�.
		sum *= digit;
		// ��յ��� ��
		answer += sum / (double)cnt;
	}

	cout << answer << '\n';

	return 0;
}