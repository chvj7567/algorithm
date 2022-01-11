#include <iostream>
#include <string>

int change(int& a, int& b, int& cnt) {
	// b�� a���� ũ�ٸ� ��ȯ �Ұ�
	if (a > b) {
		return -1;
	}
	// a�� b�� ���ٸ� ���� Ƚ�� ��ȯ
	if (a == b) {
		return cnt;
	}
	// ¦���� 2�� ������.
	if (b % 2 == 0) {
		b /= 2;
	}
	// ������ ���ڰ� 1�̸� 1�� ����.
	else if (b % 10 == 1) {
		b /= 10;
	}
	// �Ѵ� �ƴ϶�� ��ȯ �Ұ�
	else {
		return -1;
	}

	cnt++;

	// ��ȯ �Ұ� ������ ���Դٸ� �Ұ�
	if (change(a, b, cnt) == -1) {
		return -1;
	}

	return cnt;
}
int main() {
	int a, b, cnt = 1;
	std::cin >> a >> b;

	std::cout << change(a, b, cnt) << std::endl;

	return 0;
}