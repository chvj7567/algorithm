#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 네트워크 상태
std::array<std::vector<int>, 10001> network;
// 방문 확인
std::array<int, 10001> visited;

// 연결된 컴퓨터 수
int cnt = 1;

void bfs(int node) {
	// 방문 처리 후 큐에 push
	std::queue<int> q;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		// 현재 컴퓨터 위치 저장 후 큐 pop
		node = q.front();
		q.pop();

		// 연결된 다른 컴퓨터로 이동
		for (int i : network[node]) {
			// 방문한 상태가 아니라면
			// 방문 후 카운팅, 큐 push
			if (!visited[i]) {
				visited[i] = true;
				++cnt;
				q.push(i);
			}
		}
	}
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 컴퓨터 수와 네트워크 수
	int n, m;

	// 컴퓨터 수와 네트워크 수 입력
	cin >> n >> m;

	// 네트워크 상태 입력
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		network[b].push_back(a);
	}

	// 정답
	std::vector<int> answer;
	// 각 컴퓨터마다 연결가능한 컴퓨터 수를 카운팅하고
	// 그 값을 저장 후 다음 케이스를 위해 초기화 반복
	for (int i = 1; i <= n; ++i) {
		bfs(i);
		answer.push_back(cnt);
		std::fill(visited.begin(), visited.end(), false);
		cnt = 1;
	}

	// 연결 가능한 컴퓨터의 최댓값 저장
	int max_num = 0;
	for (int i : answer) {
		max_num = std::max(max_num, i);
	}

	// 연결 가능한 최댓값과 같은 컴퓨터만 오름차순으로 출력
	// 저장된 수가 각 컴퓨터의 번호 - 1과 같으므로 + 1을 해준다.
	for (int i = 0; i < answer.size(); ++i) {
		if (max_num == answer[i]) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}