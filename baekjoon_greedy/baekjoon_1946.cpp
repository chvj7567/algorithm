#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;
using std::sort;


bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	// ���� �ɻ� ������ �������� ����
	if (p1.first < p2.first) {
		return true;
	}
	return false;
}
int main() {
	// �׽�Ʈ ���̽� ��
	int test_case;
	// ���̽� �� ���� �ο� ��
	vector<int> select;
	// ���� �ο� ��
	int cnt;
	// ������ ��
	int num_of_applicants;
	// ���� ����
	vector<pair<int, int>> rank;

	// �׽�Ʈ ���̽� �� �Է�
	cin >> test_case;

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
	while (test_case > 0) {
		// ������ �� �Է�
		cin >> num_of_applicants;

		// ������ �� ��ŭ �����ɻ� ������ ���� ���� �Է�
		for (int i = 0; i < num_of_applicants; i++) {
			int doc, inter;
			cin >> doc >> inter;
			rank.push_back(make_pair(doc, inter));
		}

		// ���� ������ ����
		sort(rank.begin(), rank.end(), cmp);
		// ���� �ο� �ʱ�ȭ
		cnt = 0;
		// �����ɻ� ������ �������� ���� ������
		// ���� ������ ���ϱ� ����
		// �����ɻ� 1���� ���� ���� ����
		int maxRank = rank[0].second;

		// ���� ������ �����ɻ� �� �����麸��
		// ���ƾ� ���� �� �����Ƿ�
		// �� �������� �ְ� ���� ������ ��������
		// ���Ͽ� �� ���� ������ ����
		for (int i = 0; i < rank.size(); i++) {
			// �� ���� 1���� ������ �����Ƿ�
			// >=�� �ٿ� �����ɻ� 1���� ī��Ʈ�� ����
			if (maxRank >= rank[i].second) {
				maxRank = rank[i].second;
				cnt++;
			}
		}
		// ���� �ο� �� ����
		select.push_back(cnt);
		// ���� �ʱ�ȭ
		rank.clear();
		// ���� �׽�Ʈ ���̽�
		test_case--;
	}

	for (int cnt : select) {
		cout << cnt << endl;
	}

	return 0;
}