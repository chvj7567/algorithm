#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// ���� ������ �� ������� ����
bool cmp_one(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.second < p2.second) {
		return true;
	}
	return false;
}

// ��Ʈ ������ �� ������� ����
bool cmp_set(std::pair<int, int>& p1, std::pair<int, int>& p2) {
	if (p1.first < p2.first) {
		return true;
	}
	return false;
}

int main() {
	// ��� �� ��Ÿ �� ��, �귣���� ��, ����, �ӽ� ����
	int num, brand_num, answer, tmp_answer;
	// �� �귣���� ��Ÿ ��Ʈ ���ݰ� ���� ����
	std::vector<std::pair<int, int>> brand_price;

	// ��� �� ��Ÿ �� ���� �귣���� �� �Է�
	cin >> num >> brand_num;

	// �� �귣���� ��Ÿ ��Ʈ ���ݰ� ���� ���� �Է�
	for (int i = 0; i < brand_num; i++) {
		int price6, price1;
		cin >> price6 >> price1;
		brand_price.push_back(std::make_pair(price6, price1));
	}

	// ����
	std::vector<std::pair<int, int>> brand_copy(brand_price);
	// ��� �� ��Ÿ �� �� �� ��Ʈ�� ������ ����
	int num_set = num / 6;
	int num_one = num % 6;

	// ������ ���纻 �� ���� �Լ���� ����
	std::sort(brand_price.begin(), brand_price.end(), cmp_one);
	std::sort(brand_copy.begin(), brand_copy.end(), cmp_set);

	// ��Ÿ ���� ��� ���� 3������.
	// ������ �� ��� ���
	// ��Ʈ�� �� ��� ���
	// ������ ��Ʈ�� ��� ���

	// ������ �� ��� ���� ��Ʈ�� �� ��� ���
	answer = brand_price[0].second * num;
	tmp_answer = brand_copy[0].first * (num_set + 1);

	// �� ���� �� �ּڰ�
	answer = std::min(answer, tmp_answer);

	// ������ ��Ʈ�� ��� ���
	tmp_answer = brand_price[0].second * num_one;
	tmp_answer += brand_copy[0].first * num_set;

	// �� ���� �� �ּڰ�
	answer = std::min(answer, tmp_answer);

	cout << answer << endl;

	return 0;
}