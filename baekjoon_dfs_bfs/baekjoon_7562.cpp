#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 체스판의 길이
int n;
// 시작 좌표와 목표 좌표
int start_x, start_y, finish_x, finish_y;
// 체스판 / 방문 확인
std::array<std::array<int, 301>, 301> visited;
// 다음 좌표의 상대좌표
std::array<int, 8> dy{ -1,-2,-2,-1,1,2,2,1 };
std::array<int, 8> dx{ -2,-1,1,2,2,1,-1,-2 };

int move(int y, int x) {
	std::queue<std::pair<int, int>> q;
	// 방문 확인 겸 이동 수 저장
	// 0은 false이므로 1 저장 후
	// 마지막에 -1
	visited[y][x] = 1;
	q.push({ y,x });

	int cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 체스판을 벗어나지 않았으면
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// 방문하지 않았으면
				if (!visited[ny][nx]) {
					// 이동 수 1 추가 후 저장
					cnt = visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	// 처음 좌표에서 방문 확인을 위해 1을 주었으므로 -1 후 반환
	return visited[finish_y][finish_x] - 1;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 테스트 케이스 수
	int test_case;
	// 정답
	std::vector<int> answer;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 테스트 케이스 수 만큼 반복
	while (test_case > 0) {
		// 체스판의 길이 입력
		cin >> n;
		// 시작 좌표와 목표 좌표 입력
		cin >> start_x >> start_y;
		cin >> finish_x >> finish_y;

		// 정답 push
		answer.push_back(move(start_y, start_x));

		// 체스판 / 방문 확인 초기화
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				visited[y][x] = 0;
			}
		}
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 체스판의 길이
int n;
// 시작 좌표와 목표 좌표
int start_x, start_y, finish_x, finish_y;
// 체스판 / 방문 확인
std::array<std::array<int, 301>, 301> visited;
// 다음 좌표의 상대좌표
std::array<int, 8> dy{ -1,-2,-2,-1,1,2,2,1 };
std::array<int, 8> dx{ -2,-1,1,2,2,1,-1,-2 };

int move(int y, int x) {
	std::queue<std::pair<int, int>> q;
	// 방문 확인 겸 이동 수 저장
	// 0은 false이므로 1 저장 후
	// 마지막에 -1
	visited[y][x] = 1;
	q.push({ y,x });

	int cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 체스판을 벗어나지 않았으면
			if (!(ny < 0 || ny >= n || nx < 0 || nx >= n)) {
				// 방문하지 않았으면
				if (!visited[ny][nx]) {
					// 이동 수 1 추가 후 저장
					cnt = visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	// 처음 좌표에서 방문 확인을 위해 1을 주었으므로 -1 후 반환
	return visited[finish_y][finish_x] - 1;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 테스트 케이스 수
	int test_case;
	// 정답
	std::vector<int> answer;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 테스트 케이스 수 만큼 반복
	while (test_case > 0) {
		// 체스판의 길이 입력
		cin >> n;
		// 시작 좌표와 목표 좌표 입력
		cin >> start_x >> start_y;
		cin >> finish_x >> finish_y;

		// 정답 push
		answer.push_back(move(start_y, start_x));

		// 체스판 / 방문 확인 초기화
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				visited[y][x] = 0;
			}
		}
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}