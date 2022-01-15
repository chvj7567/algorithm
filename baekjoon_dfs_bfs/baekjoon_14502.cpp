#include <iostream>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 연구소의 세로길이, 가로길이, 정답
int height, width, answer = 0;
// 연구소의 상태
std::array<std::array<int, 9>, 9> board;
// 연구소의 상태 복사
std::array<std::array<int, 9>, 9> copy_board;
// 바이러스가 퍼질 상대 좌표
std::array<int, 4> fy{ -1,0,1,0 };
std::array<int, 4> fx{ 0,1,0,-1 };

void maxSafe() {
	std::queue<std::pair<int, int>> q;

	// 벽 3개를 세운 연구소의 상태 복사
	std::copy(board.begin(), board.end(), copy_board.begin());

	// 바이러스가 있는 좌표 큐에 push
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (copy_board[y][x] == 2) {
				q.push({ y,x });
			}
		}
	}

	while (!q.empty()) {
		// 바이러스가 있는 좌표
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = ty + fy[i];
			int nx = tx + fx[i];
			// 좌표가 연구소를 벗어나지 않았으면
			if (!(ny < 0 || ny >= height || nx < 0 || nx >= width)) {
				// 빈 공간이면 바이러스 침투
				if (copy_board[ny][nx] == 0) {
					copy_board[ny][nx] = 2;
					q.push({ ny,nx });
				}
			}
		}
	}
	// 안전 구역의 수
	int cnt = 0;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (copy_board[y][x] == 0) {
				++cnt;
			}
		}
	}

	// 안전 구역의 수가 제일 많은 경우를 저장
	answer = std::max(answer, cnt);
}

void wall(int cnt) {
	// 벽 3개를 세웠으면 바이러스 시뮬레이션
	if (cnt == 3) {
		maxSafe();
		return;
	}
	// 벽 3개를 세우는 모든 경우
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (board[y][x] == 0) {
				board[y][x] = 1;
				++cnt;
				wall(cnt);
				board[y][x] = 0;
				--cnt;
			}
		}
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 연구소의 세로길이, 가로길이 입력
	cin >> height >> width;

	// 연구소의 상태 입력(복사본에도 입력)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			copy_board[y][x] = board[y][x];
		}
	}

	wall(0);

	cout << answer << endl;

	return 0;
}