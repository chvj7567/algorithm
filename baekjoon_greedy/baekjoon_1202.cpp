#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

// 보석을 가격 순으로 내림차순 정렬을 하고
// 보석 가격이 같다면 무게 순으로 내림차순 정렬
bool cmp(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second > p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	// 보석의 수, 가방의 수
	int n, k;
	// 정답
	long long answer = 0;
	// 보석의 무게와 가격
	std::vector<std::pair<int, int>> gem;
	// 가방이 견딜 수 있는 무게
	std::multiset<int> bag;
	std::multiset<int>::iterator iter;

	// 보석의 수 와 가방의 수 입력
	scanf("%d %d", &n, &k);

	// 보석의 무게와 가격 입력
	for (int i = 0; i < n; i++) {
		int weight, price;
		scanf("%d %d", &weight, &price);
		gem.push_back(std::make_pair(price, weight));
	}

	// 정렬 함수대로 정렬
	std::sort(gem.begin(), gem.end(), cmp);

	// 가방이 견딜 수 있는 무게 입력
	for (int i = 0; i < k; i++) {
		int bag_weight;
		scanf("%d", &bag_weight);
		bag.insert(bag_weight);
	}

	// 제일 비싼 보석순으로 보석을 넣는다.
	// 가방이 견딜 수 있는 무게가 적은 순으로
	// 보석을 넣고, 넣지 못하면 넣을 수 있는
	// 가방을 찾는다. 없으면 그 보석은 포기한다.
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