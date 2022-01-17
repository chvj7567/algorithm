#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 지도의 가로, 세로 길이
int width, length;
// 지도 상태
std::array<std::array<int, 501>, 501> board;
// 방문 확인
std::array<std::array<int, 501>, 501> visited;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int dfs(int y, int x) {
	// 목표에 도착했으면 종료
	if (y == length - 1 && x == width - 1) {
		return 1;
	}
	// 이미 방문한 곳이라면 이전 기록 반환
	if (visited[y][x] != -1) {
		return visited[y][x];
	}

	// 방문 확인
	visited[y][x] = 0;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 지도를 벗어나지 않았으면
		if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
			// 다음 좌표의 값이 현재 좌표의 값보다 작으면
			if (board[y][x] > board[ny][nx]) {
				visited[y][x] += dfs(ny, nx);
			}
		}
	}

	return visited[y][x];
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 지도의 세로, 가로 길이 입력
	cin >> length >> width;

	// 지도 상태 입력
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
		}
	}

	// 최단 경로가 아닌 경로의 수 이므로
	// -1을 방문 미확인, 0을 방문 확인으로 하여
	// 카운팅 시 도착할 때만 1을 반환함(0은 더해도 0)
	// -1로 초기화
	for (int i = 0; i < 501; ++i) {
		std::fill(visited[i].begin(), visited[i].end(), -1);
	}

	cout << dfs(0, 0) << '\n';

	return 0;
}