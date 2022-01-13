#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 밭의 가로, 세로 길이, 배추의 수
int width, height, number;
// 밭의 상태
std::array<std::array<int, 51>, 51> field;
// 밭 확인
std::array<std::array<bool, 51>, 51> ok;

bool minWorm(int x, int y) {
	// 밭을 벗어나면 종료
	if (x < 0 || x >= width || y < 0 || y >= height) {
		return false;
	}

	// 배추가 없으면 종료
	if (field[x][y] == 0) {
		return false;
	}

	// 배추가 있는데 확인하지 않은 곳이면 확인
	// 배추 상하좌우로 확인
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
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 테스트 케이스 수와 각 정답
	int test_case, cnt = 0;
	// 정답들
	std::vector<int> answer;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 테스트 케이스 수 만큼 반복
	while (test_case > 0) {
		// 밭의 가로, 세로, 배추 수 입력
		cin >> width >> height >> number;

		// 배추가 있는 곳 입력
		for (int i = 0; i < number; ++i) {
			int a, b;
			cin >> a >> b;
			field[a][b] = 1;
		}

		// 연결된 곳마다 지렁이 놓기
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				if (minWorm(x, y)) {
					++cnt;
				}
			}
		}

		answer.push_back(cnt);

		// 다음 테스트 케이스를 위해 초기화
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