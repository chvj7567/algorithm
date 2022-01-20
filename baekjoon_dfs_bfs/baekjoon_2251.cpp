#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 정답
std::vector<int> answer;
// 각 물통 크기
std::array<int, 3> bucket;
// 물을 담을 수 있는 경우의 수 확인
std::array<std::array<std::array<int, 201>, 201>, 201> visited;
// 물을 옮길 경우의 상대 좌표
std::array<int, 6> from{ 0,0,1,1,2,2 };
std::array<int, 6> to{ 1,2,0,2,0,1 };

void dfs(int a, int b, int c) {
	// 이미 확인한 물의 양이면 종료
	if (visited[a][b][c]) {
		return;
	}
	// 물의 양 확인
	visited[a][b][c] = true;

	// a의 물의 양이 0이면 정답 push
	if (a == 0) {
		answer.push_back(c);
	}

	for (int i = 0; i < 6; ++i) {
		// 현재 물의 양
		std::array<int, 3> water{ a,b,c };
		// 물을 옮길 곳
		int cur_from = from[i];
		// 물이 옮겨질 곳
		int cur_to = to[i];
		// 물이 옮겨질 곳의 남은 공간
		int space = bucket[cur_to] - water[cur_to];
		// 물이 다 들어갈 공간이 있다면
		// 물을 다 옮긴다.
		if (water[cur_from] <= space) {
			water[cur_to] += water[cur_from];
			water[cur_from] -= water[cur_from];
		}
		// 물이 다 들어갈 공간이 없다면
		// 남은 공간 만큼만 옮긴다.
		else {
			water[cur_from] -= space;
			water[cur_to] += space;
		}
		dfs(water[0], water[1], water[2]);
	}
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 물통 크기 입력
	for (int i = 0; i < 3; ++i) {
		cin >> bucket[i];
	}

	dfs(0, 0, bucket[2]);

	std::sort(answer.begin(), answer.end());

	for (auto i : answer) {
		cout << i << ' ';
	}

	return 0;
}