#include <iostream>
#include <queue>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 상자의 가로길이, 세로 길이
int width, height;
// 박스 안의 토마토 상태
std::array<std::array<int, 1001>, 1001> box;
// 익었는지 확인
std::array<std::array<int, 1001>, 1001> ripe;

// 상하좌우 상대좌표(상-좌-하-우 순)
std::array<int, 4> by = { -1,0,1,0 };
std::array<int, 4> bx = { 0,1,0,-1 };

// 모든 토마토가 있었는지 확인
bool check() {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (box[y][x] == 0) {
				return false;
			}
		}
	}

	return true;
}

int minDate() {
	std::queue<std::pair<int, int>> q;

	// 익은 토마토의 좌표 큐 push 후 체크
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (box[i][j] == 1) {
				q.push({ i,j });
				ripe[i][j] = 0;
			}
		}
	}

	// 모든 토마토가 있었다면 종료
	if (check()) {
		return 0;
	}

	// 토마토가 모두 익기까지의 기간
	int cnt = 0;

	while (!q.empty()) {
		// 좌표
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// 상하좌우 좌표 확인
		for (int i = 0; i < 4; ++i) {
			int ny = y + by[i];
			int nx = x + bx[i];
			// 좌표가 상자를 벗어나지 않으면
			if (!(ny < 0 || ny >= height || nx < 0 || nx >= width)) {
				// 익었는지 확인을 안하였고 안 익은 토마토라면
				if (!ripe[ny][nx] && box[ny][nx] == 0) {
					// 토마토에 익을때까지 걸린 시간을 저장하고
					// 저장한 시간을 cnt에 기록
					cnt = ripe[ny][nx] = ripe[y][x] + 1;
					box[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}

	// 토마토가 모두 익었다면 cnt 반환
	if (check()) {
		return cnt;
	}
	// 토마토가 모두 안 익었다면 모두 익는게 불가능하므로 - 1 반환
	else {
		return -1;
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 상자의 가로길이, 세로길이 입력
	cin >> width >> height;

	// 상자 안의 토마토 상태 입력
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> box[y][x];
		}
	}

	cout << minDate() << '\n';

	return 0;
}