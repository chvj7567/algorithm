#include <iostream>
#include <vector>

int main() {
	// 임시 값 대입
	int L = -1, P = -1, V = -1;
	// 캠핑장 사용 가능 일 수 저장
	std::vector<int> able_data;

	// 무한 반복
	while (1) {
		// 각각 입력
		std::cin >> L >> P >> V;
		// 0 0 0 이 입력 되면 종료
		if (!L && !P && !V) {
			break;
		}
		// 휴가를 기준으로 연속되는 날 P로 나눠주고
		// 그 날에 이용가능한 날인 L을 곱해준다.
		int tmp = L * (V / P);

		// 연속되는 날 P보다 적은 남은 날의 경우
		// 사용 가능한 날보다 많으면
		// 사용 가능한 날을 더해주고
		// 적으면 그 일 수를 더해준다.
		if (V % P > L) {
			tmp += L;
		}
		else {
			tmp += V % P;
		}
		// 사용 가능 일 수 저장
		able_data.push_back(tmp);
	}

	for (int i = 0; i < able_data.size(); i++) {
		std::cout << "Case "<< i + 1 << ": " << able_data[i] << std::endl;
	}

	return 0;
}