#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	// ���� ��
	int n;
	// ���ǽ� ������ ���� ����
	std::priority_queue<int, std::vector<int>, std::greater<int>> finish_time;
	// ���� �ð�
	std::vector<std::pair<int, int>> time;

	// ���� �� �Է�
	cin >> n;

	// ���� �ð� �Է�
	for (int i = 0; i < n; ++i) {
		int start_time;
		int finish_time;
		cin >> start_time >> finish_time;
		time.push_back(std::make_pair(start_time, finish_time));
	}

	// ���� ���� �ð��� ���� ������ ����
	std::sort(time.begin(), time.end());

	// ù ��° ���Ǵ� �ڵ� �����̹Ƿ� ������ �ð� ����
	finish_time.push(time[0].second);

	// ������ �ð��� �������� ���� ���� ���� �ð���
	// ������ �ð� �̻��̸� ���� ���ǽǿ� ����
	// �ش����� ������ �ٸ� ���ǽǿ� �����Ͽ�
	// �켱���� ť�� ����
	for (int i = 1; i < n; ++i) {
		if (finish_time.top() <= time[i].first) {
			finish_time.pop();
		}
		finish_time.push(time[i].second);
	}

	cout << finish_time.size() << '\n';

	return 0;
}