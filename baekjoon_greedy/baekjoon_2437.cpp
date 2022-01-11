#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// ���� ���� ����
	int n, answer = 0;
	// �� ���� ����
	std::vector<int> weight;

	// ���� �� �Է�
	cin >> n;

	// �� ���� ���� �Է�
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}

	// �������� ����
	std::sort(weight.begin(), weight.end());

	// 0��°���� ���� ���԰� ���� ������ �� + 1����
	// ũ�� �� ���� ���� �� ���� ���԰� �ȴ�.
	// 0��°�� �ʱⰪ 0�� ���ϹǷ�
	// ���� ���� ���� ���԰� 2�̻��̸� �ּڰ� 1�� �ȴ�.
	for (int i = 0; i < n; i++) {
		if (weight[i] > answer + 1) {
			break;
		}
		answer += weight[i];
	}

	cout << answer + 1 << endl;

	return 0;
}