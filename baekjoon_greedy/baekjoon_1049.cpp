#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 낱개 가격이 싼 순서대로 정렬
bool cmp_one(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.second < p2.second) {
		return true;
	}
	return false;
}

// 세트 가격이 싼 순서대로 정렬
bool cmp_set(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.first < p2.first) {
		return true;
	}
	return false;
}

int main() {
	// 사야 할 기타 줄 수, 브랜드의 수, 정답, 임시 정답
	int num, brand_num, answer, tmp_answer;
	// 각 브랜드의 기타 세트 가격과 낱개 가격
	std::vector<std::pair<int, int>> brand_price;

	// 사야 할 기타 줄 수와 브랜드의 수 입력
	cin >> num >> brand_num;

	// 각 브랜드의 기타 세트 가격과 낱개 가격 입력
	for (int i = 0; i < brand_num; i++) {
		int price6, price1;
		cin >> price6 >> price1;
		brand_price.push_back(std::make_pair(price6, price1));
	}

	// 복사
	std::vector<std::pair<int, int>> brand_copy(brand_price);
	// 사야 할 기타 줄 수 중 세트와 낱개로 구분
	int num_set = num / 6;
	int num_one = num % 6;

	// 기존과 복사본 각 정렬 함수대로 정렬
	std::sort(brand_price.begin(), brand_price.end(), cmp_one);
	std::sort(brand_copy.begin(), brand_copy.end(), cmp_set);

	// 기타 줄을 사는 경우는 3가지다.
	// 낱개로 다 사는 경우
	// 세트로 다 사는 경우
	// 낱개와 세트로 사는 경우

	// 낱개로 다 사는 경우와 세트로 다 사는 경우
	answer = brand_price[0].second * num;
	tmp_answer = brand_copy[0].first * (num_set + 1);

	// 두 가지 중 최솟값
	answer = std::min(answer, tmp_answer);

	// 낱개와 세트로 사는 경우
	tmp_answer = brand_price[0].second * num_one;
	tmp_answer += brand_copy[0].first * num_set;

	// 두 가지 중 최솟값
	answer = std::min(answer, tmp_answer);

	cout << answer << endl;

	return 0;
}