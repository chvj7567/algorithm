#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	// 카드 묶음 수
	int number;
	// 각 카드 묶음의 카드 수(자동 오름차순 정렬)
	std::priority_queue<int, std::vector<int>, std::greater<int>> card_num;
	// 비교 횟수
	std::vector<int> cmp_cnt;
	// 총 비교 횟수
	int min_cmp;

	// 카드 묶음 수 입력
	std::cin >> number;

	// 각 카드 묶음의 카드 수 입력
	for (int i = 0; i < number; i++) {
		int num;
		std::cin >> num;
		card_num.push(num);
	}

	// 카드 묶음 수 - 1 만큼 비교
	while (number - 1 > 0) {
		// 카드 수가 제일 적은 카드 묶음과
		// 두번째로 적은 카드 묶음을 꺼낸다.
		int first = card_num.top();
		card_num.pop();
		int second = card_num.top();
		card_num.pop();

		// 두 카드 묶음을 합쳐서 다시 저장
		card_num.push(first + second);

		// 두 카드의 비교 횟수 저장
		cmp_cnt.push_back(first + second);

		--number;
	}

	min_cmp = 0;

	// 각 카드의 비교 횟수 합산
	for (int i : cmp_cnt) {
		min_cmp += i;
	}

	std::cout << min_cmp << std::endl;

	return 0;
}