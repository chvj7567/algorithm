#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	// ������ ����
	vector<int> coin_type;

	// ���� ������ ���� ��ǥ ���� ����, �ּ� ������ ��
	int coin_type_num, target_money, min_coin_num = 0;

	// ���� ������ ���� ��ǥ ���� ���� �Է�
	cin >> coin_type_num;
	cin >> target_money;

	// ���� ���� �Է�
	for (int i = 0; i < coin_type_num; i++) {
		// �Է��� ���� �ӽ� ����
		int tmp;
		cin >> tmp;
		coin_type.push_back(tmp);
	}

	// ���� ������ ������������ �־����Ƿ�
	// �������� �� ������ ������ ������ �� �ִ�
	// �ִ� ������ �� ������ taget_money���� ���ְ�
	// �� ������ min_coin_num�� �����ش�.
	for (int i = coin_type_num - 1; i >= 0; i--) {
		int number = target_money / coin_type[i];
		// number�� 0�̸� �� �̻� ������
		// ���Ե� �� ���ٴ� ���̴�.
		if (number != 0) {
			target_money -= number * coin_type[i];
			min_coin_num += number;
		}
	}

	cout << min_coin_num << endl;

	return 0;
}