#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 보드의 가로, 세로 길이와
// 각 경로마다 갈 수 있는 거리와
// 최대로 갈 수 있는 거리
int width, length, cnt = 0, answer = 0;
// 보드의 상태
std::array<std::string, 21> board;
// 각 알파벳 확인
std::array<bool, 26> alpha;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

void ableMove(int y, int x) {
	// cnt와 answer 중 높은 값을 정답으로 바꾼다.
	answer = std::max(answer, cnt);
	// 해당 알파벳 확인 체크
	alpha[board[y][x] - 'A'] = true;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 좌표가 보드 안이라면
		if (!(ny < 0 || ny >= length || nx < 0 || nx >= width)) {
			// 해당 알파벳이 확인되지 않은 상태라면
			if (!alpha[board[ny][nx] - 'A']) {
				alpha[board[ny][nx] - 'A'] = true;
				++cnt;
				ableMove(ny, nx);
				alpha[board[ny][nx] - 'A'] = false;
				--cnt;
			}
		}
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 보드의 세로, 가로 길이 입력
	cin >> length >> width;

	// 보드 상태 입력
	for (int i = 0; i < length; ++i) {
		std::string str;
		cin >> str;
		board[i] = str;
	}

	ableMove(0, 0);

	cout << answer + 1 << '\n';

	return 0;
}