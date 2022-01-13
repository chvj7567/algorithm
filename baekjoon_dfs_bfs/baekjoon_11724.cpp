#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 그래프
std::vector<int> graph[1001];
// 방문 확인
std::array<bool, 1001> visited;

bool connect(int v) {
	bool check = true;

	// 간선이 없는 정점일 경우
	// 하나의 연결 요소 이므로 true 반환
	if (graph[v].size() == 0) {
		return true;
	}

	// 간선으로 연결된 정점 중
	// 방문하지 않은 정점 확인
	for (int i = 0; i < graph[v].size(); ++i) {
		int tmp = graph[v][i];
		if (!visited[tmp]) {
			check = false;
		}
	}

	// 모두 방문했다면 이미 카운팅이 됐다.
	if (check) {
		return false;
	}

	// 방문 확인 체크
	visited[v] = true;

	// 방문하지 않은 정점들 확인
	for (int i = 0; i < graph[v].size(); ++i) {
		int next = graph[v][i];
		if (!visited[next]) {
			visited[next] = true;
			connect(next);
		}
	}

	return true;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 정점의 수, 간선의 수
	int n, m;
	// 정답
	int cnt = 0;

	// 정점의 수, 간선의 수 입력
	cin >> n >> m;

	// 간선 입력
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		// 양방향
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 오름차순 정렬
	for (int i = 0; i < n; ++i) {
		std::sort(graph[i].begin(), graph[i].end());
	}

	// 연결 요소 찾기
	for (int i = 1; i <= n; ++i) {
		if (connect(i)) {
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}