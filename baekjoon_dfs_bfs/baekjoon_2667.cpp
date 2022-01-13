#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ����/���� ����, ���� ��
int length, cnt;
// ��
std::vector<std::string> land;
// �� Ȯ��
std::array<std::array<int, 26>, 26> check;
// ����
std::vector<int> answer;

void apartNumber(int x, int y) {
	// ���� ������ ����� ����
	if (x < 0 || x >= length || y < 0 || y >= length) {
		return;
	}

	// ���� ������ ����
	if (land[x][y] == '0') {
		return;
	}

	// Ȯ������ ���� ���̸� Ȯ�� �� ī����
	if (!check[x][y]) {
		check[x][y] = true;
		++cnt;

		// �����¿�� �� Ȯ��
		apartNumber(x + 1, y);
		apartNumber(x - 1, y);
		apartNumber(x, y + 1);
		apartNumber(x, y - 1);
	}
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �Է� ���ڿ�
	std::string str;

	// ���� �Է�
	cin >> length;

	// �� �迭 �Է�
	for (int i = 0; i < length; ++i) {
		cin >> str;
		land.push_back(str);
	}

	// �� ������ Ȯ��
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < length; ++x) {
			cnt = 0;
			apartNumber(x, y);
			// cnt�� 0�̸� �� ���� ���� ���� ��
			if (cnt != 0) {
				answer.push_back(cnt);
			}
		}
	}

	// ���� ���� ���� ������ ����
	std::sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}