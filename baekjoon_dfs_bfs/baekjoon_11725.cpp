#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// ����� ��
int n;
// Ʈ��
std::array<std::vector<int>, 100001> tree;
// �� ����� �θ�
std::array<int, 100001> parent;

void parentNode(int n) {
	// �ڽ� ��尡 ������ ����
	if (tree[n].size() == 0) {
		return;
	}

	for (int i = 0; i < tree[n].size(); ++i) {
		int child = tree[n][i];
		// �θ� ��尡 Ȯ�ε��� �ʾ�����
		if (!parent[child]) {
			parent[child] = n;
			parentNode(child);
		}
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��� �� �Է�
	cin >> n;

	// ���� ��� �Է�
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		// �����
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	// ��Ʈ ��� ǥ��
	parent[1] = 1;
	parentNode(1);

	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << '\n';
	}

	return 0;
}