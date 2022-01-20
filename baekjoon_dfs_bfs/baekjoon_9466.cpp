#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// ���� �̷� �ο�
int cnt = 0;
// �׷����� ��Ÿ�� ����
std::array<int, 100001> graph;
// �湮 Ȯ��
std::array<bool, 100001> visited;
// �� Ȯ��
std::array<bool, 100001> team;

void dfs(int n) {
	// �湮 Ȯ��
	visited[n] = true;

	// ������ ����
	int next = graph[n];

	// ������ ������ Ȯ������
	// �ʾҴٸ� ���
	if (!visited[next]) {
		dfs(next);
	}
	// ������ ������ �̹� Ȯ���ߴٸ�
	// (���� �̷�����ٸ�)
	// ���� ���� ���ٸ�
	else if (!team[next]) {
		// �ٽ� ����Ŭ�� ���� �ο� �� Ȯ��
		while (next != n) {
			++cnt;
			next = graph[next];
		}
		// �ڱ� �ڽ� ����
		++cnt;
	}
	// �� Ȯ��
	// ���� �̷��� ���ص�
	// �̷��� ���Ѵٴ� �� Ȯ���ߴٴ� ǥ��
	team[n] = true;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// �׽�Ʈ ���̽� ��
	int test_case;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// ����
	std::vector<int> answer;
	while (test_case > 0) {
		// �л� ��
		int students;
		// �л� �� �Է�
		cin >> students;
		// ���� ���� �Է�
		for (int i = 1; i <= students; ++i) {
			cin >> graph[i];
		}
		// �� ����
		for (int i = 1; i <= students; ++i) {
			dfs(i);
		}
		// ��ü �ο����� ���� �̷� ��� ����
		// ���� ������ ���� �л����� ��
		answer.push_back(students - cnt);

		// ���� �׽�Ʈ ���̽��� ���� �ʱ�ȭ
		cnt = 0;
		std::fill(visited.begin(), visited.end(), false);
		std::fill(team.begin(), team.end(), false);
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}