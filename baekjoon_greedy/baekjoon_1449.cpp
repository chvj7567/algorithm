#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// ���� ���� ���� ��, �������� ����, �ʿ� ������ ����
	int n, tape, cnt = 0;
	// ������ ���� ��ġ
	std::vector<int> repair;

	// ���� ���� ���� ���� �������� ���� �Է�
	cin >> n >> tape;

	// ������ ���� ��ġ �Է�
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		repair.push_back(tmp);
	}

	// �������� ����
	std::sort(repair.begin(), repair.end());

	// �������� ��ġ�� ��� �������� ���̸�ŭ
	// ���޾� ���� �� �ִ� ��ġ�� ��´�.
	// ó�� ��ġ�� 1�̰� �������� ���̰� 3�̶��
	// ���� �� �ִ� ���� ��ġ��
	// (ó�� ��ġ  + �������� ����) - 1 ��ŭ�̴�.
	// <�� �Ἥ -1�� ���Ե��� �ʰ� �ߴ�.
	for (int i = 0; i < n; i++) {
		int tmp = repair[i];
		for (int j = i + 1; j < n; j++) {
			if (repair[j] < tmp + tape) {
				i++;
			}
		}
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}