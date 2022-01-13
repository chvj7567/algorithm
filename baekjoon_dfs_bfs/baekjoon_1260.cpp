#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

// 노드
std::vector<int> node[1001];
// 방문 확인
std::array<bool, 1001> visited;

void dfs(int v) {
	// 해당 노드가 방문했다면 종료
	if (visited[v]) {
		return;
	}

	// 방문하지 않았다면 방문 처리 후 출력
	visited[v] = true;
	cout << v << " ";

	// 인접 노드들 모두에게 dfs 실행
	for (int i = 0; i < node[v].size(); i++) {
		dfs(node[v][i]);
	}

}

void bfs(int v) {
	std::queue<int> q;

	// 탐색 시작 노드 방문 처리 후 출력
	visited[v] = true;
	cout << v << " ";

	// 큐 push
	q.push(v);

	// 큐가 빌 때까지
	while (!q.empty()) {
		// 큐의 최상단 노드 값 저장
		int num = q.front();
		// 큐 pop
		q.pop();

		// 인접 노드들 먼저 방문
		for (int i = 0; i < node[num].size(); ++i) {
			int value = node[num][i];
			// 방문 하지 않았다면
			// 방문 처리, 출력 후 큐 push
			if (!visited[value]) {
				visited[value] = true;
				cout << value << " ";
				q.push(value);
			}
		}
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 정점 갯수, 간선 갯수, 탐색 시작 번호
	int n, m, v;

	// 정점 갯수, 간선 갯수, 탐색 시작 번호 입력
	cin >> n >> m >> v;

	// 간선 입력
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		// 양방향
		node[a].push_back(b);
		node[b].push_back(a);
	}

	// 오름차순 정렬
	for (int i = 1; i <= n; ++i) {
		std::sort(node[i].begin(), node[i].end());
	}

	dfs(v);

	cout << '\n';

	// 방문 확인 초기화
	for (int i = 1; i <= n; ++i) {
		visited[i] = false;
	}

	bfs(v);

	return 0;
}