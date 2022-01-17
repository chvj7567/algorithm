#include <iostream>
#include <vector>
#include <array>
#include <queue>

using std::cin;
using std::cout;

// 사람 수와 관계 수
int n, v;
// 촌수를 나타낼 두 사람
int p1, p2;
// 각 사람간의 관계 그래프
std::array<std::vector<int>, 101> graph;
// 관계 확인
std::array<int, 101> check;

int bfs(int v) {
	std::queue<int> q;
	// 관계 확인 체크 / 촌수 확인
	check[v] = 1;
	q.push(v);

	while (!q.empty()) {
		int cur_n = q.front();
		q.pop();

		for (int i = 0; i < graph[cur_n].size(); ++i) {
			int next_n = graph[cur_n][i];
			// 관계를 확인하지 않았다면
			if (!check[next_n]) {
				// 촌수를 나타낼 사람을 찾았다면
				// 이전에 저장된 촌수를 반환
				// 1을 추가하기 전이므로 -1을 안해도 된다.
				if (next_n == p2) {
					return check[cur_n];
				}
				check[next_n] = check[cur_n] + 1;
				q.push(next_n);
			}
		}
	}

	// 촌수를 나타내지 못하면 -1 반환
	return -1;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 사람 수 입력
	cin >> n;
	// 촌수를 나타낼 두 사람 입력
	cin >> p1 >> p2;
	// 관계 수 입력
	cin >> v;

	// 관계 입력
	for (int i = 0; i < v; ++i) {
		int a, b;
		cin >> a >> b;
		// 양방향
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(p1) << '\n';

	return 0;
}