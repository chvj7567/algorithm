#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 노드의 수
int n;
// 트리
std::array<std::vector<int>, 100001> tree;
// 각 노드의 부모
std::array<int, 100001> parent;

void parentNode(int n) {
	// 자식 노드가 없으면 종료
	if (tree[n].size() == 0) {
		return;
	}

	for (int i = 0; i < tree[n].size(); ++i) {
		int child = tree[n][i];
		// 부모 노드가 확인되지 않았으면
		if (!parent[child]) {
			parent[child] = n;
			parentNode(child);
		}
	}
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 노드 수 입력
	cin >> n;

	// 연결 노드 입력
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		// 양방향
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	// 루트 노드 표시
	parent[1] = 1;
	parentNode(1);

	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << '\n';
	}

	return 0;
}