#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// 보드의 가로, 세로 길이
int width, length;
// 정답
std::vector<int> answer;
// 보드 상태
std::array<std::string, 1001> board;
// 방문 확인 및 벽 부숨 확인
std::array<std::array<std::array<int, 1001>, 1001>, 2> visited;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int shortestPath(int y, int x) {
	std::queue<std::tuple<int, int, int>> q;
	// 맨 앞의 1은 부술 수 있는 벽의 수
	// 값은 움직인 거리
	visited[1][y][x] = 1;
	q.push({ 1,y,x });

	while (!q.empty()) {
		// 부술 수 있는 벽의 수
		int destroy = std::get<0>(q.front());
		// 현재 좌표
		y = std::get<1>(q.front());
		x = std::get<2>(q.front());
		q.pop();
		
		// 목적지에 도착했다면 움직인 거리를 반환하고 종료
		if (y == length - 1 && x == width - 1) {
			return visited[destroy][y][x];
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 보드를 벗어나지 않았다면
			if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
				// 방문하지 않았고 갈 수 있는 곳이라면(벽이 없다면)
				// 이동 수를 1 추가하고 큐에 push
				if (!visited[destroy][ny][nx] && board[ny][nx] == '0') {
					visited[destroy][ny][nx] = visited[destroy][y][x] + 1;
					q.push({ destroy, ny, nx });
				}
				// 벽이고 벽을 부술 수 있는 상태라면
				// 벽을 부순 후(부술 수 있는 벽 수 감소) 이동 거리 저장
				// 큐에 push
				else if (destroy > 0 && board[ny][nx] == '1') {
					visited[destroy - 1][ny][nx] = visited[destroy][y][x] + 1;
					q.push({ destroy - 1, ny, nx });
				}

			}
		}
	}

	return -1;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 보드의 세로, 가로 길이 입력
	cin >> length >> width;

	// 보드의 상태 입력
	for (int i = 0; i < length; ++i) {
		std::string str;
		cin >> str;
		board[i] = str;
	}

	cout << shortestPath(0, 0) << '\n';

	return 0;
}