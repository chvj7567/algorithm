#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 노드의 수와 끝 노드, 정답
int n, end_n, answer = 0;
// 트리 상태
std::array<std::vector<std::pair<int, int>>, 10001> tree;
// 방문 확인
std::array<bool, 10001> visited;

void dfs(int n, int d) {
	// 이미 방문 했다면 종료
	if (visited[n]) {
		return;
	}
	// 제일 거리가 먼 지점의
	// 거리와 노드 번호 저장
	if (answer < d) {
		answer = d;
		end_n = n;
	}

	// 방문 처리
	visited[n] = true;

	// 다음 좌표 재귀
	for (int i = 0; i < tree[n].size(); ++i) {
		int next_n = tree[n][i].first;
		int next_d = tree[n][i].second;
		dfs(next_n, next_d + d);
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 노드 수 입력
	cin >> n;

	// 트리 상태 입력
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		// 양방향
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	// 임의의 지점에서 제일 먼 지점 찾기(끝점 찾기)
	dfs(1, 0);
	
	// 방문 확인 초기화
	std::fill(visited.begin(), visited.end(), false);

	// 끝점에서 제일 먼 지점 찾기(트리의 지름)
	dfs(end_n, 0);

	cout << answer << '\n';

	return 0;
}