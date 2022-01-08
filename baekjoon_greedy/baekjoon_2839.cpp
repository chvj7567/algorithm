#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 설탕 봉지의 최소 갯수를 반환하는 함수
int minNumberSugar(int sugar) {
	// 5kg 봉지는 담을 수 있는 최대 봉지부터 감소하고
	// 3kg 봉지는 0개에서 1개씩 늘려가면서
	// 딱 나누어 떨어질때까지 반복
	for (int i = sugar / 5; i >= 0; i--) {
		for (int j = 0; j <= sugar / 3; j++) {
			// 5의 배수이면 5로 나눈 몫 반환
			if (sugar % 5 == 0) {
				return sugar / 5;
			}
			else {
				// 5kg 봉지로 담을 수 있는
				// 무게를 뺀 나머지 설탕 무게
				int remainder_sugar = sugar - (i * 5);

				// 나머지 설탕 무게가 3의 배수이면
				// 5kg 봉지 수와 3kg 봉지수의 합 반환
				if (remainder_sugar % 3 == 0) {
					return i + remainder_sugar / 3;
				}
			}
		}
	}
	// 5kg과 3kg으로 불가능할 경우 -1 반환
	return -1;
}

int main() {
	// 설탕 무게
	int sugar;

	// 설탕 무게 입력
	cin >> sugar;

	cout << minNumberSugar(sugar) << endl;

	return 0;
}