#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
// 정점의 수, 정답, 끝 정점 번호
int n, answer = 0, end_num = 0;
// 트리 상태
std::array<std::vector<std::pair<int, int>>, 100001> tree;
// 방문 확인
std::array<bool, 100001> visited;

void dfs(int num, int weight) {
	// 이미 방문 했다면 종료
	if (visited[num]) {
		return;
	}
	// 제일 거리가 먼 지점의
	// 거리와 노드 번호 저장
	if (answer < weight) {
		answer = weight;
		end_num = num;
	}

	// 방문 처리
	visited[num] = true;

	// 다음 좌표 재귀
	for (int i = 0; i < tree[num].size(); ++i) {
		int next_num = tree[num][i].first;
		int next_weight = tree[num][i].second;
		dfs(next_num, weight + next_weight);
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 정점의 수 입력
	cin >> n;

	// 트리 상태 입력
	for (int i = 0; i < n; ++i) {
		int node;
		cin >> node;
		while (1) {
			int a, b;
			cin >> a;
			if (a == -1) {
				break;
			}
			cin >> b;
			tree[node].push_back({ a,b });
		}
	}
	// 임의의 지점에서 제일 먼 지점 찾기(끝점 찾기)
	dfs(1, 0);

	// 방문 확인 초기화
	std::fill(visited.begin(), visited.end(), false);

	// 끝점에서 제일 먼 지점 찾기(트리의 지름)
	dfs(end_num, 0);

	cout << answer << '\n';

	return 0;
}