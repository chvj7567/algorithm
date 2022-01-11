#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// �ּڰ��� �ִ� ����
void minMax(std::string str, int& min, int& max) {
	// 5�� 6�� ���� 5�� ����
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '5' || str[i] == '6') {
			str[i] = '5';
		}
	}
	// �ּڰ�
	min = stoi(str);

	// 5�� 6�� ���� 6���� ����
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '5' || str[i] == '6') {
			str[i] = '6';
		}
	}
	// �ִ�
	max = stoi(str);
}

int main() {
	// �� ��
	int a, b;
	// a�� �ּڰ�, b�� �ּڰ�
	int min_a, min_b;
	// a�� �ִ�, b�� �ִ�
	int max_a, max_b;

	// �� �� �Է�
	cin >> a >> b;

	// a�� b�� �ּڰ�, �ִ�
	minMax(std::to_string(a), min_a, max_a);
	minMax(std::to_string(b), min_b, max_b);

	cout << min_a + min_b << " " << max_a + max_b << endl;

	return 0;
}