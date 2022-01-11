#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// ������ ������ ����� ���� �Ǵ� 0�� ������ ����
	int num, pos_cnt = 0, neg_cnt = 0;
	// ���� ��
	int result = 0;
	// ���� �� ����
	std::vector<int> seq;

	// ������ ���� �Է�
	std::cin >> num;

	// ������ �� �Է�
	for (int i = 0; i < num; i++) {
		int number;
		std::cin >> number;
		seq.push_back(number);
		// ������ ���� ������� ���� �Ǵ� 0���� ī����
		number > 0 ? pos_cnt++ : neg_cnt++;
	}

	// �������� ����
	std::sort(seq.begin(), seq.end());

	// 0�϶��� ���ص� 0�̱⿡ ������� ����
	for (int i = 0; i < seq.size(); i++) {
		// ������ ���
		if (seq[i] < 0) {
			// ������ ������ 2�� �̻��� ��
			// 0�� ���ԵǾ� �ֱ⿡ ������ ������
			// 0�� ���� �� ���ؼ� 0�� �ȴ�.
			if (neg_cnt > 1) {
				// �� ���� ���ؼ� ���� ���� ���Ѵ�.
				// i + 1�� ���ϱ� ���� �ε�����
				// 1�� �� �����ְ� ī������ -2 ���ش�.
				result += seq[i] * seq[i + 1];
				i++;
				neg_cnt -= 2;
			}
			// ������ ������ 1���� ��
			// 0�� ���� ������ ���� ����
			// ���� �״�θ� �����ش�.
			else {
				result += seq[i];
				neg_cnt--;
			}
		}
		// ����� ���
		else if (seq[i] > 0) {
			// 1�� ��� ���ϴ� �ͺ���
			// �����ִ°� �� ũ�⿡ �����ش�.
			if (seq[i] == 1) {
				result += 1;
				pos_cnt--;
			}
			else {
				// ����� Ȧ���� ���� ���
				// ���������̱⿡ ù �����
				// 1�� ������ ���� ���� ���̱⿡
				// ¦�� �� �´� ���� �����ش�.
				// Ȧ���� ��� 1���� ����ȴ�.
				if (pos_cnt % 2 == 1) {
					result += seq[i];
					pos_cnt--;
				}
				// ����� ¦������ ���
				// �� ���� ���ؼ� ���� ���� �����ش�.
				else {
					result += seq[i] * seq[i + 1];
					i++;
					pos_cnt -= 2;
				}
			}
		}
	}

	std::cout << result << std::endl;

	return 0;
}