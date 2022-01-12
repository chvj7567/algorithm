#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// ���ο� ���� ����
	int height, width;
	// ����
	int answer = 0;

	// ���ο� ���� ���� �Է�
	cin >> height >> width;

	// ���̰� 0 �Ǵ� 1�� ���
	// �� �����̹Ƿ� ó�� �湮�� 1ĭ�� ��
	// ���̰� 2�� ���
	// 2���� ���� �ۿ� �� �����̹Ƿ�
	// �ִ� 3�� ������ �� ����
	// ���̰� 3�̻��� ���(�� �̻��� �� ����.)
	// ���� ���̿� ����
	// 4���� �������� ������ �� ����
	// 4���� ���� ��� �Ŀ��� ���η�
	// ���� ���� �����̴�(���η� 1ĭ)
	// ���ϸ� ����Ͽ� ���
	switch (height) {
	case 0:
	case 1:
		answer = 1;
		break;
	case 2:
		switch (width) {
		case 0:
		case 1:
		case 2:
			answer = 1;
			break;
		case 3:
		case 4:
			answer = 2;
			break;
		case 5:
		case 6:
			answer = 3;
			break;
		default:
			answer = 4;
			break;
		}
		break;
	default:
		switch (width) {
		case 0:
		case 1:
			answer = 1;
			break;
		case 2:
			answer = 2;
			break;
		case 3:
			answer = 3;
			break;
		case 4:
		case 5:
		case 6:
			answer = 4;
			break;
		case 7:
			answer = 5;
			break;
		default:
			answer = 5;
			width -= 7;
			answer += width;
			break;
		}
		break;
	}

	cout << answer << endl;

	return 0;
}