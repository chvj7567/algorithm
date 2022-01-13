#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 가로/세로 길이, 단지 수
int length, cnt;
// 땅
std::vector<std::string> land;
// 집 확인
std::array<std::array<int, 26>, 26> check;
// 정답
std::vector<int> answer;

void apartNumber(int x, int y) {
	// 땅의 범위를 벗어나면 종료
	if (x < 0 || x >= length || y < 0 || y >= length) {
		return;
	}

	// 집이 없으면 종료
	if (land[x][y] == '0') {
		return;
	}

	// 확인하지 않은 집이면 확인 후 카운팅
	if (!check[x][y]) {
		check[x][y] = true;
		++cnt;

		// 상하좌우로 집 확인
		apartNumber(x + 1, y);
		apartNumber(x - 1, y);
		apartNumber(x, y + 1);
		apartNumber(x, y - 1);
	}
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 입력 문자열
	std::string str;

	// 길이 입력
	cin >> length;

	// 집 배열 입력
	for (int i = 0; i < length; ++i) {
		cin >> str;
		land.push_back(str);
	}

	// 각 땅마다 확인
	for (int y = 0; y < length; ++y) {
		for (int x = 0; x < length; ++x) {
			cnt = 0;
			apartNumber(x, y);
			// cnt가 0이면 그 곳은 집이 없는 곳
			if (cnt != 0) {
				answer.push_back(cnt);
			}
		}
	}

	// 단지 수가 적은 곳부터 정렬
	std::sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}