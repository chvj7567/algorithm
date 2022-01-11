#include <iostream>
#include <string>

int main() {
	// 받을 문자열
	std::string str;
	// '0' 또는 '1'을 받을 문자
	char num;
	// 인덱스 번호를 받을 임시 변수와
	// 뒤집는 횟수를 저장할 변수
	int tmp = -2, cnt = 0;

	// 문자열 입력
	std::cin >> str;
	
	// 문자는 크게 3가지 형태다.
	// 111, 101, 01
	// 한 문자를 기준으로 전체가 그 문자인 경우
	// 양쪽이 그 문자인 경우
	// 한쪽이 그 문자인 경우
	// 첫번째 문자가 몇 덩어리(?) 나오는지 알면
	// 그것이 최소 횟수인 것이다.
	
	// 첫번째와 다른 문자를 저장한다.
	if (str[0] == '0') {
		num = '1';
	}
	else {
		num = '0';
	}

	// 첫번째 문자와 다른 문자가 몇 덩어리(?)
	// 나오는지 문자열 전체를 검사
	for (int i = 0; i < str.size();i++) {
		// 문자가 지정한 문자와 같은지
		// 연속된 문자인지(전의 인덱스 번호를 저장)
		// 확인하여 덩어리(?)채로 횟수를 늘린다.
		if (str[i] == num && i != tmp + 1) {
			cnt++;
			tmp = i;
		}
		else if(str[i] == num) {
			tmp = i;
		}
	}

	std::cout << cnt << std::endl;

	return 0;
}