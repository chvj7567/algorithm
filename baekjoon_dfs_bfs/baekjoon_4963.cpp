#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 지도의 가로길이, 세로길이
int w, h;
// 지도의 상태
std::array<std::array<int, 51>, 51> board;
// 확인 여부
std::array<std::array<bool, 51>, 51> check;
// 다음 좌표의 상대 좌표(좌측 상단부터 시계 방향 순)
std::array<int, 8> by = { -1,-1,-1,0,0,1,1,1 };
std::array<int, 8> bx = { -1,0,1,-1,1,-1,0,1 };

bool dfs(int y, int x) {
	// 좌표가 지도를 벗어나면 종료
	if (x < 0 || x >= w || y < 0 || y >= h) {
		return false;
	}

	// 좌표가 바다면 종료
	if (board[y][x] == 0) {
		return false;
	}

	// 확인을 안한 좌표이면 확인
	if (!check[y][x]) {
		check[y][x] = true;
		// 다음 좌표를 확인
		for (int i = 0; i < 8; ++i) {
			dfs(y + by[i], x + bx[i]);
		}
		return true;
	}

	return false;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 정답
	std::vector<int> answer;

	// 무한 반복
	while (1) {
		// 지도의 가로길이, 세로길이 입력
		cin >> w >> h;

		// 0 0 이 입력되면 종료
		if (!w && !h) {
			break;
		}

		// 지도의 상태 입력
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				cin >> board[y][x];
			}
		}

		// 섬의 갯수
		int cnt = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (dfs(y, x)) {
					++cnt;
				}
			}
		}

		// 다음 케이스를 위해 초기화
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				board[y][x] = 0;
				check[y][x] = false;
			}
		}
		// 섬의 갯수 저장
		answer.push_back(cnt);
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}