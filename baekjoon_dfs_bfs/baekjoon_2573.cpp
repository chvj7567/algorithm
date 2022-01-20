#include <iostream>
#include <array>

using std::cin;
using std::cout;

// 행과 열 길이
int row, col;
// 바다 상태
std::array<std::array<int, 301>, 301> sea;
// 방문 확인
std::array<std::array<int, 301>, 301> visited;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// 얼음 녹이는 함수
int melts(int y, int x) {
	int result = 0;

	// 빙산이 아니면 종료
	if (sea[y][x] == 0) {
		return 0;
	}
	// 빙산이면 4면의 바다 수 만큼 녹는다.
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= row || nx < 0 || nx >= col) {
			continue;
		}
		if (sea[ny][nx] == 0) {
			--result;
		}
	}
	// 빙산의 녹는 양 반환
	return result;
}

bool dfs(int y, int x) {
	// 좌표가 벗어나면 종료
	if (y < 0 || y >= row || x < 0 || x >= col) {
		return false;
	}
	// 이미 방문했거나 바다라면 종료
	if (visited[y][x] || sea[y][x] == 0) {
		return false;
	}
	// 방문 처리
	visited[y][x] = true;

	// 다음 좌표에 대해 재귀
	for (int i = 0; i < 4; ++i) {
		dfs(y + dy[i], x + dx[i]);
	}

	return true;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 빙산 조각의 수와 정답
	int cnt = 0, answer = 0;

	// 행과 열 입력
	cin >> row >> col;

	// 바다 상태 입력
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			cin >> sea[y][x];
		}
	}

	// 첫 상태 확인
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			if (dfs(y, x)) {
				++cnt;
			}
		}
	}

	// 빙산이 이미 두 조각 이상이면 종료
	// 문제에서 이 예외는 없는 모양이다.
	if (cnt >= 2) {
		return 0;
	}

	// 초기화
	for (int y = 0; y < row; ++y) {
		for (int x = 0; x < col; ++x) {
			visited[y][x] = false;
		}
	}

	// 빙산이 두 조각 이상으로 분리될 때까지 반복
	while (cnt < 2) {
		// 빙산의 녹는 양 저장
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				visited[y][x] = melts(y, x);
			}
		}

		// 빙산 녹이는 단계
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				if (sea[y][x] != 0) {
					if ((sea[y][x] += visited[y][x]) < 0) {
						sea[y][x] = 0;
					}
					visited[y][x] = false;
				}
			}
		}
		// 1년 지남
		++answer;

		cnt = 0;
		// 얼음이 녹고 나서 상태 확인
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				if (dfs(y, x)) {
					++cnt;
				}
			}
		}
		if (cnt == 0) {
			// 빙산이 다 녹을때까지
			// 2조각 이상으로 되지 않았을 때
			answer = 0;
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}