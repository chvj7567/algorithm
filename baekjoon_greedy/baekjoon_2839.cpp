#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ���� ������ �ּ� ������ ��ȯ�ϴ� �Լ�
int minNumberSugar(int sugar) {
	// 5kg ������ ���� �� �ִ� �ִ� �������� �����ϰ�
	// 3kg ������ 0������ 1���� �÷����鼭
	// �� ������ ������������ �ݺ�
	for (int i = sugar / 5; i >= 0; i--) {
		for (int j = 0; j <= sugar / 3; j++) {
			// 5�� ����̸� 5�� ���� �� ��ȯ
			if (sugar % 5 == 0) {
				return sugar / 5;
			}
			else {
				// 5kg ������ ���� �� �ִ�
				// ���Ը� �� ������ ���� ����
				int remainder_sugar = sugar - (i * 5);

				// ������ ���� ���԰� 3�� ����̸�
				// 5kg ���� ���� 3kg �������� �� ��ȯ
				if (remainder_sugar % 3 == 0) {
					return i + remainder_sugar / 3;
				}
			}
		}
	}
	// 5kg�� 3kg���� �Ұ����� ��� -1 ��ȯ
	return -1;
}

int main() {
	// ���� ����
	int sugar;

	// ���� ���� �Է�
	cin >> sugar;

	cout << minNumberSugar(sugar) << endl;

	return 0;
}