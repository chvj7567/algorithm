#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 숲의 크기와 정답
int n, answer = 0;
// 숲의 상태
std::array<std::array<int, 501>, 501> board;
// 방문 확인 겸 이동 칸 수 저장
std::array<std::array<int, 501>, 501> visited;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int dfs(int y, int x) {
	// 이미 방문했다면 이전 값 반환
	if (visited[y][x] != 0) {
		return visited[y][x];
	}

	// 1칸 이동 확인
	visited[y][x] = 1;

	// 다음 좌표로 이동
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 숲을 벗어나지 않았다면
		if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
			// 다음 칸의 대나무가 더 많다면
			if (board[y][x] < board[ny][nx]) {
				// 각 칸마다 최대 이동 값 저장
				visited[y][x] = std::max(visited[y][x], dfs(ny, nx) + 1);
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

	// 숲의 크기 입력
	cin >> n;

	// 숲의 상태 입력
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> board[y][x];
		}
	}

	// 각 칸에서 제일 많이 이동할 수 있는 칸 저장
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			answer = std::max(answer, dfs(y, x));
		}
	}

	cout << answer << '\n';

	return 0;
}