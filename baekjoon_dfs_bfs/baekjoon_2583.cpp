#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 모눈종이의 가로, 세로 길이와
// 직사각형의 수와 각 영역의 비중
int width, length, number, cnt = 0;
// 모눈종이 상태
std::array<std::array<bool, 101>, 101> board;
// 방문 확인
std::array<std::array<bool, 101>, 101> visited;
// 다음 좌표의 상대좌표
std::array<int, 4> dy{ -1,0,1,0 };
std::array<int, 4> dx{ 0,1,0,-1 };

int area(int y, int x) {
	// 좌표가 모눈 종이를 벗어나면 종료
	if (y < 0 || y >= length || x < 0 || x >= width) {
		return 0;
	}
	// 이미 방문했거나 빈 좌표가 아니라면 종료
	if (visited[y][x] || board[y][x] == 1) {
		return 0;
	}
	// 방문 처리 후 카운팅
	visited[y][x] = true;
	++cnt;
	// 다음 좌표에 대해 재귀
	for (int i = 0; i < 4; ++i) {
		area(y + dy[i], x + dx[i]);
	}

	return cnt;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 모눈 종이의 세로, 가로, 직사각형의 수 입력
	cin >> length >> width >> number;

	// 직사각형의 좌표 입력
	for (int i = 0; i < number; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		// 좌표를 통해 모눈종이에 표시
		for (int y = b; y < d; ++y) {
			for (int x = a; x < c; ++x) {
				board[y][x] = 1;
			}
		}
	}

	// 각 영역의 수 구하기
	std::vector<int> answer;
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < width; ++x) {
			// 영역의 수가 1이상 일때만 기록 후
			// 카운팅 초기화(음수는 나오지 않음)
			if (area(y, x)) {
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 오름차순 정렬
	std::sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i : answer) {
		cout << i << ' ';
	}

	return 0;
}