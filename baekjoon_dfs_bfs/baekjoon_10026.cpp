#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 그림의 가로, 세로 길이
int n;
// 방문 확인
std::array<std::array<bool, 101>, 101> check;

// 다음 좌표의 상대좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

// 방문 확인 초기화
void initCheck() {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			check[y][x] = false;
		}
	}
}

bool countColor(std::array<std::string, 101>& picture, int y, int x, char color) {
	// 좌표가 그림을 벗어나면 종료
	if (y < 0 || y >= n || x < 0 || x >= n) {
		return false;
	}
	// 이미 확인한 좌표면 종료
	if (check[y][x]) {
		return false;
	}
	// 색이 다르면 종료
	if (picture[y][x] != color) {
		return false;
	}
	// 방문 확인 체크
	check[y][x] = true;
	// 다음 좌표로 재귀
	for (int i = 0; i < 4; ++i) {
		countColor(picture, y + dy[i], x + dx[i], color);
	}

	return true;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 적록색약이 아닌 사람이 보는 그림과
	// 적록색약인 사람이 보는 그림
	std::array<std::string, 101> normal_picture;
	std::array<std::string, 101> rg_picture;

	// 그림의 가로, 세로 길이
	cin >> n;

	// 그림 상태 입력
	for (int y = 0; y < n; ++y) {
		std::string str;
		cin >> str;
		normal_picture[y] = str;
		rg_picture[y] = str;
	}

	// 적록색약인 사람이 보는 그림은
	// 적색과 녹색이 같게 보인다.
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (rg_picture[y][x] == 'G') {
				rg_picture[y][x] = 'R';
			}
		}
	}

	// 적록색약이 아닌 사람이 보는 그림의 영역 수
	int normal_cnt = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (countColor(normal_picture, y, x, normal_picture[y][x])) {
				++normal_cnt;
			}
		}
	}

	// 방문 확인 초기화
	initCheck();

	// 적록색약인 사람이 보는 그림의 영역 수
	int rg_cnt = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (countColor(rg_picture, y, x, rg_picture[y][x])) {
				++rg_cnt;
			}
		}
	}

	cout << normal_cnt << " " << rg_cnt << '\n';

	return 0;
}