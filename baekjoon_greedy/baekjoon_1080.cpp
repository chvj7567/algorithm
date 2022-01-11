#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// a, b 행렬
int a[51][51], b[51][51];
// 연산 시 변화될 좌표들의 상대 좌표 9곳
int ch[9][2] = { -1,-1,
				  0,-1,
				  1,-1,
				  -1,0,
				   0,0,
				   1,0,
				  -1,1,
				   0,1,
				   1,1, };

// 0이면 1로 1이면 0으로 변환 연산
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
	// 행, 열, 변환 연산 수
	int row, col, cnt = 0;

	// 행과 열 입력
	cin >> row >> col;

	// 행과 열 입력을 위한 문자열
	std::string str;

	// a행력 입력
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	// b행렬 입력
	for (int i = 0; i < row; i++) {
		cin >> str;
		for (int j = 0; j < col; j++) {
			b[i][j] = str[j] - '0';
		}
	}

	// 각 테두리에서는 변환 연산을 못하기에
	// 범위는 1부터 행과 열 -1
	// 변환 연산을 하는 기준은
	// 좌측 상단에서 우측 하단으로 실행할 경우
	// 하나의 변환 연산이 유일하게 관여할 수 있는
	// 상대 좌표는 좌측 상단의 좌표이다.
	// 즉, a의 좌측 상단의 좌표가 b와 다르다면 변환 연산을 실행한다.
	for (int y = 1; y < row - 1; y++) {
		for (int x = 1; x < col - 1; x++) {
			if (a[y - 1][x - 1] != b[y - 1][x - 1]) {
				change(row, col, y, x);
				cnt++;
			}
		}
	}

	// 비교
	bool check = true;

	// 같은 행렬이 되었는지 확인
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