#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min;

int main() {
	// 도시의 수
	int num_of_city;
	// 총 가격과, 최저 값 주유비의 가격
	long long price, min_city;
	// 각 도시의 주유비와 도시 간의 거리
	vector<long long> city, dis;

	// 도시의 수 입력
	cin >> num_of_city;

	// 각 도시 간의 거리 입력
	for (int i = 0; i < num_of_city - 1; i++) {
		int tmp;
		cin >> tmp;
		dis.push_back(tmp);
	}

	// 각 도시의 주유비 입력
	for (int i = 0; i < num_of_city; i++) {
		int tmp;
		cin >> tmp;
		city.push_back(tmp);
	}

	// 1번째 도시에서 2번째 도시까지는
	// 무조건 1번째 도시에서 주유 후 가야함
	min_city = city[0];
	price = city[0] * dis[0];

	// 다음 도시의 주유비와 비교 후 싼 주유비로 주유
	for (int i = 1; i < city.size() - 1; i++) {
		min_city = min(min_city, city[i]);
		price += min_city * dis[i];
	}

	cout << price << endl;

	return 0;
}