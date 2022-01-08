#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	// 동전의 종류
	vector<int> coin_type;

	// 동전 종류의 수와 목표 돈의 가격, 최소 동전의 수
	int coin_type_num, target_money, min_coin_num = 0;

	// 동전 종류의 수와 목표 돈의 가격 입력
	cin >> coin_type_num;
	cin >> target_money;

	// 동전 종류 입력
	for (int i = 0; i < coin_type_num; i++) {
		// 입력을 위한 임시 변수
		int tmp;
		cin >> tmp;
		coin_type.push_back(tmp);
	}

	// 동전 종류가 오름차순으로 주어지므로
	// 역순으로 각 동전의 종류가 차지할 수 있는
	// 최대 갯수와 그 가격을 taget_money에서 빼주고
	// 그 수량을 min_coin_num에 더해준다.
	for (int i = coin_type_num - 1; i >= 0; i--) {
		int number = target_money / coin_type[i];
		// number가 0이면 더 이상 동전이
		// 포함될 수 없다는 뜻이다.
		if (number != 0) {
			target_money -= number * coin_type[i];
			min_coin_num += number;
		}
	}

	cout << min_coin_num << endl;

	return 0;
}