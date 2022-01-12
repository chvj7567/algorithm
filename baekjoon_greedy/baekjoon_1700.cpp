#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// c�� c++ ����ȭ ��Ȱ��ȭ
	// cin�� cout �ӵ� ���
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ��Ƽ�� ���� ���� ���� ��ǰ ��, ����
	int n, k, answer = 0;
	// ����� ��ǰ ����
	std::vector<int> use;
	// ��Ƽ��
	std::array<int, 101> multitap = {};

	// ��Ƽ�� ���� ���� ���� ��ǰ �� �Է�
	cin >> n >> k;

	// ����� ��ǰ ���� �Է�
	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;
		use.push_back(tmp);
	}

	for (int i = 0; i < k; ++i) {
		// �ش� ��Ⱑ ��� ������ Ȯ��
		bool check = false;
		for (int j = 0; j < n; ++j) {
			if (multitap[j] == use[i]) {
				check = true;
				break;
			}
		}
		// ��� ���̸� ���� ��ǰ����
		if (check) {
			continue;
		}
		// ��� ���� �ƴ϶��
		else {
			// �ӽ� �ε��� ����
			int tmp_idx;
			// ��Ƽ�ǿ� �� �ڸ��� �ִ��� Ȯ��
			for (int j = 0; j < n; ++j) {
				if (multitap[j] == 0) {
					check = true;
					tmp_idx = j;
					break;
				}
			}
			// ��Ƽ�ǿ� �� �ڸ��� �ִٸ� ����Ѵ�.
			// ��� �ϰ� ���� ��ǰ����
			if (check) {
				multitap[tmp_idx] = use[i];
				continue;
			}
			// ��Ƽ�ǿ� �� �ڸ��� ���ٸ�
			else {
				// ���� ���߿� ����� ��ǰ�� ���� ���� ����
				std::vector<std::pair<int, int>> later;
				for (int j = 0; j < n; ++j) {
					// ���� ���߿� ����� ��ǰ�� ���� ���� ī����
					int cnt = 0;
					if (multitap[j] != 0) {
						for (int l = i; l < k; ++l) {
							if (multitap[j] == use[l]) {
								break;
							}
							cnt++;
						}
						later.push_back(std::make_pair(cnt, j));
					}
				}

				// ���� ���߿� ����� �ε����� 0 �ε����� ������ ����
				std::sort(later.begin(), later.end(), std::greater<std::pair<int, int>>());

				// ���� ���߿� ����� ��ǰ�� ã�Ƽ� ���� ��ǰ���� ����
				for (int j = 0; j < n; ++j) {
					if (multitap[j] == multitap[later[0].second]) {
						multitap[j] = use[i];
						++answer;
					}
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}