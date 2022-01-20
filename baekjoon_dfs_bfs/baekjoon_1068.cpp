#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// 트리 상태
std::array<std::vector<int>, 51> tree;
// 삭제 트리
std::array<bool, 51> del;

void dfs(int node) {
	// 삭제 처리가 됐다면 종료
	if (del[node]) {
		return;
	}
	// 삭제 처리
	del[node] = true;

	// 자식 노드도 재귀
	for (int i :tree[node]) {
		dfs(i);
	}
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 노드 수
	int n;

	// 노드 수 입력
	cin >> n;

	// 트리 입력
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == -1) {
			continue;
		}
		tree[a].push_back(i);
	}

	// 삭제 노드
	int del_node;
	// 삭제 노드 입력
	cin >> del_node;

	dfs(del_node);

	// 리프 노드 수
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		// 사이즈가 0이고 삭제 처리가 안됐다면(리프 노드 이면)
		if (tree[i].size() == 0 && !del[i]) {
			++cnt;
		}
		// 삭제 처리가 안됐고 사이즈가 1이면서 자식 노드가 삭제 처리됐다면
		// 일자형 트리가 이어졌을 때 예외 처리
		// 삭제 표시만 했을 뿐 실제로 삭제처리가 되지 않았으므로,
		// 삭제 처리된 자식 노드 1개만 가지고 있는
		// 삭제 처리되지 않은 노드는 리프 노드이다.
		else if (!del[i] && tree[i].size() == 1 && del[tree[i][0]]) {
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}