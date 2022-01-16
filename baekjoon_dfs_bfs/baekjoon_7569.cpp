#include <iostream>
#include <array>
#include <queue>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;

// 상자의 가로, 세로, 높이 길이
int width, length, height;
// 박스의 상태
std::array<std::array<std::array<int, 101>, 101>, 101> box;
// 박스 확인
std::array<std::array<std::array<int, 101>, 101>, 101> check;

// 다음 좌표의 상대좌표
std::array<int, 6> dz{ 1,-1,0,0,0,0 };
std::array<int, 6> dy{ 0,0,-1,0,1,0 };
std::array<int, 6> dx{ 0,0,0,1,0,-1 };

int dateRipe() {
	std::queue<std::tuple<int, int, int>> q;

	bool end_ripe = true;
	bool no_ripe = true;
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (box[z][y][x] == 1) {
					check[z][y][x] = 1;
					q.push({ z,y,x });
				}
				if (box[z][y][x] == 0) {
					end_ripe = false;
				}
				if (box[z][y][x] != 0) {
					no_ripe = false;
				}
			}
		}
	}
	// 토마토가 이미 다 익었다면 0 반환
	if (end_ripe) {
		return 0;
	}
	// 익은 토마토가 없다면 -1 반환
	if (no_ripe) {
		return -1;
	}

	int cnt = 0;
	while (!q.empty()) {
		// 현재 좌표
		int z = std::get<0>(q.front());
		int y = std::get<1>(q.front());
		int x = std::get<2>(q.front());
		q.pop();

		// 다음 좌표
		for (int i = 0; i < 6; ++i) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 좌표가 상자를 벗어나지 않았다면
			if (!(nz < 0 || nz >= height || ny < 0 || ny >= length || nx < 0 || nx >= width)) {
				// 확인하지 않은 좌표이고 익지 않은 토마토가 있다면
				if (!check[nz][ny][nx] && box[nz][ny][nx] == 0) {
					cnt = check[nz][ny][nx] = check[z][y][x] + 1;
					box[nz][ny][nx] = 1;
					q.push({ nz,ny,nx });
				}
			}
		}
	}

	// 토마토가 다 익었는지 확인
	bool all_ripe = true;
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (box[z][y][x] == 0) {
					all_ripe = false;
				}
			}
		}
	}

	// 토마토가 다익었다면 처음에 익은 토마토 확인을 위해
	// 1로 초기화 했으므로 cnt - 1 반환
	if (all_ripe) {
		return cnt - 1;
	}
	// 토마토가 다 안익었다면 다 익게 할 수 없으므로 -1 반환
	else {
		return -1;
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 상자의 가로, 세로, 높이 입력
	cin >> width >> length >> height;

	// 상자의 상태 입력
	for (int z = 0; z < height; ++z) {
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				cin >> box[z][y][x];
			}
		}
	}

	cout << dateRipe() << '\n';

	return 0;
}