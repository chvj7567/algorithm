#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// S�� ������ unsigned int�� �����̴�.
	unsigned int S, N = 1;

	// S �Է�
	cin >> S;

	// 1���� 1�� �߰��� ���� ���� ��
	// �� ���� S�� �Ѿ�� �� ���� ��
	// ��ü�� ������ �����̸�,
	// ������ ���� +1�ؼ� ���� ����
	// �� N-1�̴�.
	while (S >= N) {
		S -= N;
		N++;
	}
	cout << N - 1 << endl;

	return 0;
}