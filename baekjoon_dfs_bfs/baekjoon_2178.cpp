#include <iostream>
#include <string>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// 세로 길이, 가로 길이
int n, m;
// 미로판
std::array<std::array<int, 101>, 101> board;
// 방문 확인
std::array<std::array<int, 101>, 101> visited;
// 상하좌우 상대좌표(상-우-하-좌 순)
int by[4] = { -1,0,1,0 };
int bx[4] = { 0,1,0,-1 };

int bfs(int x, int y) {
	// 큐에 방문 기록 후 저장(기록은 이동거리)
	std::queue<std::pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {
		// 방문한 장소의 좌표 받고 삭제
		y = q.front().first;
		x = q.front().second;
		q.pop();

		// 목표 지점에 도달할 시 반복문 종료
		if (y == n - 1 && x == m - 1) {
			break;
		}

		// 상하좌우 좌표를 살펴서 갈 수 있는곳 탐색
		for (int i = 0; i < 4; ++i) {
			int ny = y + by[i];
			int nx = x + bx[i];
			// 미로를 벗어나는 좌표가 아니라면
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= m)) {
				// 방문하지 않은 곳이고 갈 수 있는 곳이면(1 이면)
				if (!visited[ny][nx] && board[ny][nx] == 1) {
					// 이동 거리를 + 1 해준 후 큐에 저장
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}

	// 도착 좌표는 총 이동거리가 저장되어 있다.
	return visited[n - 1][m - 1];
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 세로 길이, 가로 길이 입력
	cin >> n >> m;
	
	// 미로판 생성
	for (int y = 0; y < n; ++y) {
		std::string str;
		cin >> str;
		for (int x = 0; x < m; ++x) {
			board[y][x] = str[x] - '0';
		}
	}

	cout << bfs(0, 0) << '\n';

	return 0;
}