#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// ������ ����� �ܾ�
	std::string doc, word;
	// �˻� ��ġ ����
	int check_first = -1;
	// ���� �ܾ� Ȯ��, ����
	int check_cnt = 0, answer = 0;

	// ������ ����� �ܾ� �Է�
	getline(cin, doc, '\n');
	getline(cin, word, '\n');

	// ������ �ܾ� ��
	for (int i = 0; i < doc.size(); i++) {
		for (int j = 0; j < word.size(); j++) {
			// �ܾ��� ù�ڰ� ������ ù �� ��ġ�� ������
			// ������ ����� ���� �� �ش� ��ġ ���
			// �ܾ �Ϻθ� ���� �� �� ��ġ���� ����
			if (check_first == -1 && j != 0 && doc[i] == word[0]) {
				check_first = i;
			}
			// �ܾ ���ٸ� �ܾ��� ����ŭ ī�����ϰ�
			// ������ ��ġ�� �Բ� �̵�
			if (doc[i] == word[j]) {
				check_cnt++;
				i++;
			}
			else {
				// �ܾ �ٸ��� �߰��� ���� ��ġ�� ���� �ִٸ�
				// ���� ��ġ�� �Ѱ��ְ� -1�� �ʱ�ȭ
				if (check_first != -1) {
					i = check_first - 1;
					check_first = -1;
				}
				// ī���� �ʱ�ȭ
				check_cnt = 0;
				break;
			}
		}
		// �ܾ� ī������ �ܾ��� ���� ���ٸ� ������ ������ Ȯ��
		// ������ ��ġ�� 1�� �� �����ϹǷ� �̸� 1����
		// ī���ð� ���� ��ġ �ʱ�ȭ
		if (check_cnt == word.size()) {
			answer++;
			i--;
			check_cnt = 0;
			check_first = -1;
		}
	}

	cout << answer << endl;

	return 0;
}