#include <iostream>
#include <vector>
#include <array>
#include <queue>

using std::cin;
using std::cout;

// 정점과 간선의 수
int v, e;
// 그래프 상태
std::array<std::vector<int>, 200001> graph;
// 방문 확인
std::array<int, 20001> visited;

// 색깔로 구분
// WHITE = 0(칠하지 않음)
// RED = 1
// BLACK = 2
enum Color {
	WHITE,
	RED,
	BLACK
};

bool bfs(int n) {
	std::queue<std::pair<int, int>> q;
	// 정점의 번호와 색을 큐에 push
	q.push({ n, visited[n] });

	// 큐가 빌 때까지
	while (!q.empty()) {
		// 현재 정점 번호와 색 저장 후 큐 pop
		int cur = q.front().first;
		int color = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			// 다음 정점
			int next = graph[cur][i];
			// 다음 정점의 색이 비었다면
			if (visited[next] == WHITE) {
				// 검은색이면 빨간색으로 칠한다.
				if (color == BLACK) {
					visited[next] = RED;
				}
				// 빨간색이면 검은색으로 칠한다.
				else {
					visited[next] = BLACK;
				}
				q.push({ next, visited[next] });
			}
			// 다음 정점의 색이 칠해져 있다면
			else {
				// 색이 같다면 이분 그래프 실패 처리
				if (visited[next] == color) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 테스트 케이스 수
	int test_case;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 정답
	std::vector<bool> answer;

	while (test_case > 0) {
		// 정점 수와 간선 수 입력
		cin >> v >> e;

		// 그래프 입력
		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			// 양방향
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		// 시작 정점 색 임의 지정
		visited[1] = RED;

		// 이분 그래프 판단
		bool result = true;
		for (int i = 1; i <= v; ++i) {
			if (!bfs(i)) {
				result = false;
			}
		}
		answer.push_back(result);

		// 다음 테스트 케이스를 위해 초기화
		for (int i = 1; i <= v; ++i) {
			visited[i] = false;
			graph[i].clear();
		}

		--test_case;
	}

	for (auto a : answer) {
		if (a) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}