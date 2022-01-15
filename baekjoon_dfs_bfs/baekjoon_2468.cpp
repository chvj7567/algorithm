#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 지역의 가로, 세로 길이
int n;
// 지역의 높이 상태
std::array<std::array<int, 101>, 101> area;
// 안전 지역 확인
std::array<std::array<bool, 101>, 101> safe;
// 다음에 확인할 상대 좌표
std::array<int, 4> by = { -1,0,1,0 };
std::array<int, 4> bx = { 0,1,0,-1 };

bool safeArea(int cur_x, int cur_y, int rain) {
	// 좌표가 확인한 상태면 종료
	if (safe[cur_y][cur_x]) {
		return false;
	}
	// 좌표가 침수영역이면 종료
	if (area[cur_y][cur_x] <= rain) {
		return false;
	}

	std::queue<std::pair<int, int>> q;
	safe[cur_y][cur_x] = true;
	q.push({ cur_y,cur_x });

	while (!q.empty()) {
		// 현재 좌표
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();
		// 다음 좌표 확인
		for (int i = 0; i < 4; ++i) {
			int ny = cur_y + by[i];
			int nx = cur_x + bx[i];
			// 좌표가 지역을 벗어나지 않으면
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// 좌표를 확인하지 않았고 안전지역이면
				if (!safe[ny][nx] && area[ny][nx] > rain) {
					safe[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}

	return true;
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 지역의 가로, 세로 길이 입력
	cin >> n;

	// 강수량이 지역에 영향을 끼치는 최소, 최대치
	int minRain = 101;
	int maxRain = 0;
	
	// 각 지역의 높이 입력
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> area[i][j];
			minRain = std::min(minRain, area[i][j]);
			maxRain = std::max(maxRain, area[i][j]);
		}
	}

	// 모든 지역이 같은 높이인지 확인
	int same = area[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (area[i][j] != same) {
				same = -1;
			}
		}
	}

	// 모든 지역이 같은 높이라면
	// 최대 안전지역의 수는 1이므로
	// 1을 출력하고 종료
	if (same != -1) {
		cout << 1 << endl;
		return 0;
	}

	// 정답
	int answer = 0;
	// 강수량 반복
	for (int k = minRain; k < maxRain; ++k) {
		// 각 강수량마다 안전 지역 수량
		int cnt = 0;
		// 강수량이 바뀔때마다 초기화
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				safe[i][j] = false;
			}
		}
		// 각 강수량마다 안전 지역 수량 체크
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (safeArea(i, j, k)) {
					++cnt;
				}
			}
		}
		// 안전 지역 수량이 많은 곳의 기록 저장
		answer = std::max(answer, cnt);
	}

	cout << answer << endl;

	return 0;
}