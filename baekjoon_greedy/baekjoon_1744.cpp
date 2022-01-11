#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// 수열의 갯수와 양수와 음수 또는 0을 저장할 변수
	int num, pos_cnt = 0, neg_cnt = 0;
	// 최종 값
	int result = 0;
	// 수열 값 저장
	std::vector<int> seq;

	// 수열의 갯수 입력
	std::cin >> num;

	// 수열의 수 입력
	for (int i = 0; i < num; i++) {
		int number;
		std::cin >> number;
		seq.push_back(number);
		// 수열의 수가 양수인지 음수 또는 0인지 카운팅
		number > 0 ? pos_cnt++ : neg_cnt++;
	}

	// 오름차순 정렬
	std::sort(seq.begin(), seq.end());

	// 0일때는 더해도 0이기에 계산하지 않음
	for (int i = 0; i < seq.size(); i++) {
		// 음수일 경우
		if (seq[i] < 0) {
			// 음수의 갯수가 2개 이상일 때
			// 0도 포함되어 있기에 마지막 음수는
			// 0이 있을 시 곱해서 0이 된다.
			if (neg_cnt > 1) {
				// 두 수를 곱해서 최종 값에 더한다.
				// i + 1을 쓰니까 다음 인덱스에
				// 1을 더 더해주고 카운팅을 -2 해준다.
				result += seq[i] * seq[i + 1];
				i++;
				neg_cnt -= 2;
			}
			// 음수의 갯수가 1개일 때
			// 0이 없이 음수만 남을 경우는
			// 음수 그대로를 더해준다.
			else {
				result += seq[i];
				neg_cnt--;
			}
		}
		// 양수일 경우
		else if (seq[i] > 0) {
			// 1일 경우 곱하는 것보다
			// 더해주는게 더 크기에 더해준다.
			if (seq[i] == 1) {
				result += 1;
				pos_cnt--;
			}
			else {
				// 양수가 홀수개 있을 경우
				// 오름차순이기에 첫 양수는
				// 1을 제외한 가장 작은 수이기에
				// 짝이 안 맞는 수는 더해준다.
				// 홀수일 경우 1번만 실행된다.
				if (pos_cnt % 2 == 1) {
					result += seq[i];
					pos_cnt--;
				}
				// 양수가 짝수개일 경우
				// 두 수를 곱해서 최종 값에 더해준다.
				else {
					result += seq[i] * seq[i + 1];
					i++;
					pos_cnt -= 2;
				}
			}
		}
	}

	std::cout << result << std::endl;

	return 0;
}