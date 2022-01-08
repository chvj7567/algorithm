#include <iostream>
#include <vector>

int main() {
	// �ӽ� �� ����
	int L = -1, P = -1, V = -1;
	// ķ���� ��� ���� �� �� ����
	std::vector<int> able_data;

	// ���� �ݺ�
	while (1) {
		// ���� �Է�
		std::cin >> L >> P >> V;
		// 0 0 0 �� �Է� �Ǹ� ����
		if (!L && !P && !V) {
			break;
		}
		// �ް��� �������� ���ӵǴ� �� P�� �����ְ�
		// �� ���� �̿밡���� ���� L�� �����ش�.
		int tmp = L * (V / P);

		// ���ӵǴ� �� P���� ���� ���� ���� ���
		// ��� ������ ������ ������
		// ��� ������ ���� �����ְ�
		// ������ �� �� ���� �����ش�.
		if (V % P > L) {
			tmp += L;
		}
		else {
			tmp += V % P;
		}
		// ��� ���� �� �� ����
		able_data.push_back(tmp);
	}

	for (int i = 0; i < able_data.size(); i++) {
		std::cout << "Case "<< i + 1 << ": " << able_data[i] << std::endl;
	}

	return 0;
}