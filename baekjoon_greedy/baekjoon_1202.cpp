#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

// ������ ���� ������ �������� ������ �ϰ�
// ���� ������ ���ٸ� ���� ������ �������� ����
bool cmp(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second > p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	// ������ ��, ������ ��
	int n, k;
	// ����
	long long answer = 0;
	// ������ ���Կ� ����
	std::vector<std::pair<int, int>> gem;
	// ������ �ߵ� �� �ִ� ����
	std::multiset<int> bag;
	std::multiset<int>::iterator iter;

	// ������ �� �� ������ �� �Է�
	scanf("%d %d", &n, &k);

	// ������ ���Կ� ���� �Է�
	for (int i = 0; i < n; i++) {
		int weight, price;
		scanf("%d %d", &weight, &price);
		gem.push_back(std::make_pair(price, weight));
	}

	// ���� �Լ���� ����
	std::sort(gem.begin(), gem.end(), cmp);

	// ������ �ߵ� �� �ִ� ���� �Է�
	for (int i = 0; i < k; i++) {
		int bag_weight;
		scanf("%d", &bag_weight);
		bag.insert(bag_weight);
	}

	// ���� ��� ���������� ������ �ִ´�.
	// ������ �ߵ� �� �ִ� ���԰� ���� ������
	// ������ �ְ�, ���� ���ϸ� ���� �� �ִ�
	// ������ ã�´�. ������ �� ������ �����Ѵ�.
	for (int i = 0; i < n; i++) {
		iter = bag.lower_bound(gem[i].second);
		if (iter != bag.end()) {
			bag.erase(iter);
			answer += gem[i].first;
		}
	}

	std::cout << answer << std::endl;

	return 0;
}