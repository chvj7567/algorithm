#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// ��Ʈ��ũ �����
std::vector<int> connect[101];
// ���� Ȯ��
std::array<int, 101> infection;

int virus(int target) {
	// ���� üũ
	infection[target] = true;
	int cnt = 0;

	// ��Ʈ��ũ ����θ� ���� �������� ����
	// ��ǻ�� ����
	for (int i = 0; i < connect[target].size(); ++i) {
		int next = connect[target][i];
		if (!infection[next]) {
			infection[next] = true;
			++cnt;
			cnt += virus(next);
		}
	}

	return cnt;
}

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ��ǻ�� ���� ���� ��Ʈ��ũ ��
	int computer_num, network_num;

	// ��ǻ�� ���� ��Ʈ��ũ �� �Է�
	cin >> computer_num;
	cin >> network_num;

	// ��Ʈ��ũ ���� �Է�
	for (int i = 0; i < network_num; ++i) {
		int a, b;
		cin >> a >> b;
		// �����
		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	// �������� ����
	for (int i = 0; i < computer_num; ++i) {
		std::sort(connect[i].begin(), connect[i].end());
	}

	cout << virus(1) << '\n';

	return 0;
}