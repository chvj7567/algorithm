#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
// ������ ��, ����, �� ���� ��ȣ
int n, answer = 0, end_num = 0;
// Ʈ�� ����
std::array<std::vector<std::pair<int, int>>, 100001> tree;
// �湮 Ȯ��
std::array<bool, 100001> visited;

void dfs(int num, int weight) {
	// �̹� �湮 �ߴٸ� ����
	if (visited[num]) {
		return;
	}
	// ���� �Ÿ��� �� ������
	// �Ÿ��� ��� ��ȣ ����
	if (answer < weight) {
		answer = weight;
		end_num = num;
	}

	// �湮 ó��
	visited[num] = true;

	// ���� ��ǥ ���
	for (int i = 0; i < tree[num].size(); ++i) {
		int next_num = tree[num][i].first;
		int next_weight = tree[num][i].second;
		dfs(next_num, weight + next_weight);
	}
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ �� �Է�
	cin >> n;

	// Ʈ�� ���� �Է�
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
	// ������ �������� ���� �� ���� ã��(���� ã��)
	dfs(1, 0);

	// �湮 Ȯ�� �ʱ�ȭ
	std::fill(visited.begin(), visited.end(), false);

	// �������� ���� �� ���� ã��(Ʈ���� ����)
	dfs(end_num, 0);

	cout << answer << '\n';

	return 0;
}