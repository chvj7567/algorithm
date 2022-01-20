#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Ʈ�� ����
std::array<std::vector<int>, 51> tree;
// ���� Ʈ��
std::array<bool, 51> del;

void dfs(int node) {
	// ���� ó���� �ƴٸ� ����
	if (del[node]) {
		return;
	}
	// ���� ó��
	del[node] = true;

	// �ڽ� ��嵵 ���
	for (int i :tree[node]) {
		dfs(i);
	}
}
int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��� ��
	int n;

	// ��� �� �Է�
	cin >> n;

	// Ʈ�� �Է�
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == -1) {
			continue;
		}
		tree[a].push_back(i);
	}

	// ���� ���
	int del_node;
	// ���� ��� �Է�
	cin >> del_node;

	dfs(del_node);

	// ���� ��� ��
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		// ����� 0�̰� ���� ó���� �ȵƴٸ�(���� ��� �̸�)
		if (tree[i].size() == 0 && !del[i]) {
			++cnt;
		}
		// ���� ó���� �ȵư� ����� 1�̸鼭 �ڽ� ��尡 ���� ó���ƴٸ�
		// ������ Ʈ���� �̾����� �� ���� ó��
		// ���� ǥ�ø� ���� �� ������ ����ó���� ���� �ʾ����Ƿ�,
		// ���� ó���� �ڽ� ��� 1���� ������ �ִ�
		// ���� ó������ ���� ���� ���� ����̴�.
		else if (!del[i] && tree[i].size() == 1 && del[tree[i][0]]) {
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}