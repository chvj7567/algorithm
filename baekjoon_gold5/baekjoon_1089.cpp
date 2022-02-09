#include <iostream>
#include <string>
#include <array>
#include <vector>

using std::cin;
using std::cout;

// 10의 n승 층의 n
int n;
// 안내판의 상태
std::array<std::string, 5> board = {};
// 해당 인덱스의 숫자가 가능한지 여부
std::array<std::array<bool, 10>, 10> isAble = {};
// 각 자릿수에 가능한 숫자들
std::array<std::vector<int>, 10> isAbleNumber = {};

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// n 입력
	cin >> n;

	// 안내판의 상태 입력
	for (int i = 0; i < 5; ++i) {
		cin >> board[i];
	}

	// 검사 전 해당 숫자들이 다 가능하다가 판단
	for (int i = 0; i < n; ++i) {
		std::fill(isAble[i].begin(), isAble[i].end(), true);
	}

	// 각 숫자들의 불이 꺼진 부분이(문제 참조)
	// 안내판의 상태에서 불이 켜져있다면 해당 숫자는 불가능 처리
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

	// 각 자릿수에 가능한 숫자들 저장
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (isAble[i][j]) {
				isAbleNumber[i].push_back(j);
			}
		}
	}

	// 하나의 자리에 모든 숫자가 불가능하다면
	// 전체 숫자는 무의미함을 확인
	bool check = false;
	for (int i = 0; i < n; ++i) {
		if (isAbleNumber[i].empty()) {
			check = true;
		}
	}

	// 숫자가 불가능하다면 -1 출력
	if (check) {
		cout << -1 << '\n';
		return 0;
	}

	// 정답
	double answer = 0.0;
	for (int i = n - 1, digit = 1; i >= 0; --i, digit *= 10) {
		long long sum = 0;
		int cnt = 0;
		// 해당 자릿수의 모든 숫자들의 합
		for (auto a : isAbleNumber[i]) {
			sum += a;
			++cnt;
		}
		// 해당 자릿수에 실질적인 단위로 더한다.
		sum *= digit;
		// 평균들의 합
		answer += sum / (double)cnt;
	}

	cout << answer << '\n';

	return 0;
}