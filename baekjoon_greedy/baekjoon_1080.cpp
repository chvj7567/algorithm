#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// a, b ���
int a[51][51], b[51][51];
// ���� �� ��ȭ�� ��ǥ���� ��� ��ǥ 9��
int ch[9][2] = { -1,-1,
				  0,-1,
				  1,-1,
				  -1,0,
				   0,0,
				   1,0,
				  -1,1,
				   0,1,
				   1,1, };

// 0�̸� 1�� 1�̸� 0���� ��ȯ ����
void change(int row, int col, int y, int x) {
	for (int i = 0; i < 9; i++) {
		if (a[y + ch[i][0]][x + ch[i][1]] == 1) {
			a[y + ch[i][0]][x + ch[i][1]] = 0;
		}
		else {
			a[y + ch[i][0]][x + ch[i][1]] = 1;
		}
	}
	return;
}

int main() {
	// ��, ��, ��ȯ ���� ��
	int row, col, cnt = 0;

	// ��� �� �Է�
	cin >> row >> col;

	// ��� �� �Է��� ���� ���ڿ�
	std::string str;

	// a��� �Է�
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	// b��� �Է�
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			b[i][j] = str[j] - '0';
		}
	}

	// �� �׵θ������� ��ȯ ������ ���ϱ⿡
	// ������ 1���� ��� �� -1
	// ��ȯ ������ �ϴ� ������
	// ���� ��ܿ��� ���� �ϴ����� ������ ���
	// �ϳ��� ��ȯ ������ �����ϰ� ������ �� �ִ�
	// ��� ��ǥ�� ���� ����� ��ǥ�̴�.
	// ��, a�� ���� ����� ��ǥ�� b�� �ٸ��ٸ� ��ȯ ������ �����Ѵ�.
	for (int y = 1; y < row - 1; y++) {
		for (int x = 1; x < col - 1; x++) {
			if (a[y - 1][x - 1] != b[y - 1][x - 1]) {
				change(row, col, y, x);
				cnt++;
			}
		}
	}

	// ��
	bool check = true;

	// ���� ����� �Ǿ����� Ȯ��
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (a[y][x] != b[y][x]) {
				check = false;
			}
		}
	}

	if (check) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}