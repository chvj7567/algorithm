#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	// ī�� ���� ��
	int number;
	// �� ī�� ������ ī�� ��(�ڵ� �������� ����)
	std::priority_queue<int, std::vector<int>, std::greater<int>> card_num;
	// �� Ƚ��
	std::vector<int> cmp_cnt;
	// �� �� Ƚ��
	int min_cmp;

	// ī�� ���� �� �Է�
	std::cin >> number;

	// �� ī�� ������ ī�� �� �Է�
	for (int i = 0; i < number; i++) {
		int num;
		std::cin >> num;
		card_num.push(num);
	}

	// ī�� ���� �� - 1 ��ŭ ��
	while (number - 1 > 0) {
		// ī�� ���� ���� ���� ī�� ������
		// �ι�°�� ���� ī�� ������ ������.
		int first = card_num.top();
		card_num.pop();
		int second = card_num.top();
		card_num.pop();

		// �� ī�� ������ ���ļ� �ٽ� ����
		card_num.push(first + second);

		// �� ī���� �� Ƚ�� ����
		cmp_cnt.push_back(first + second);

		--number;
	}

	min_cmp = 0;

	// �� ī���� �� Ƚ�� �ջ�
	for (int i : cmp_cnt) {
		min_cmp += i;
	}

	std::cout << min_cmp << std::endl;

	return 0;
}