#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;

// 종이의 가로, 세로 길이
int width, length;
// 보드 상태
std::array<std::array<int, 101>, 101> board;
// 녹을 치즈
std::array<std::array<bool, 101>, 101> melt_check;
// 외부 공기 확인
std::array<std::array<bool, 101>, 101> visited;
// 다음 좌표의 상대 좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// 외부 공기 확인하는 dfs
void dfs(int y, int x) {
	if (y < 0 || y >= length || x < 0 || x >= width) {
		return;
	}

	if (visited[y][x] || board[y][x] == 1) {
		return;
	}

	visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		dfs(y + dy[i], x + dx[i]);
	}
}

void melts(int y, int x) {
	// 치즈가 아니면 종료
	if (board[y][x] == 0) {
		return;
	}

	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 닿은면이 외부 공기이면
		if (board[ny][nx] == 0 && visited[ny][nx]) {
			++cnt;
		}
	}

	// 외부 공기가 두 면 이상 닿아있으면 체크
	if (cnt >= 2) {
		melt_check[y][x] = true;
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 종이의 세로, 가로 길이 입력
	cin >> length >> width;

	// 치즈의 수
	int cheese = 0;
	// 치즈가 있는지 체크
	bool nothing = true;
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			cin >> board[y][x];
			// 치즈가 있다면
			if (board[y][x] == 1) {
				nothing = false;
				++cheese;
			}
		}
	}

	// 치즈가 없다면 0 출력 후 종료
	if (nothing) {
		cout << 0 << '\n';
		return 0;
	}

	// 외부 공기 확인
	dfs(0, 0);

	// 치즈가 다 녹는데 걸리는 시간
	int hour = 0;

	while (1) {
		// 1시간
		++hour;

		// 녹을 치즈 확인
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				melts(y, x);
			}
		}

		// 치즈 녹인 후 해당 자리에서
		// 다시 외부 공기 확인
		for (int y = 0; y < length; ++y) {
			for (int x = 0; x < width; ++x) {
				if (melt_check[y][x]) {
					board[y][x] = 0;
					dfs(y, x);
					--cheese;
					melt_check[y][x] = false;
				}
			}
		}

		// 치즈가 없다면 반복문 종료
		if (cheese == 0) {
			break;
		}
	}

	cout << hour << '\n';

	return 0;
}