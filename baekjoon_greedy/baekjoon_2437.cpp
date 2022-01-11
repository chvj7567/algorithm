#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// 추의 수와 정답
	int n, answer = 0;
	// 각 추의 무게
	std::vector<int> weight;

	// 추의 수 입력
	cin >> n;

	// 각 추의 무게 입력
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}

	// 오름차순 정렬
	std::sort(weight.begin(), weight.end());

	// 0번째부터 추의 무게가 전의 무게의 합 + 1보다
	// 크면 그 값이 만들 수 없는 무게가 된다.
	// 0번째는 초기값 0과 비교하므로
	// 제일 작은 추의 무게가 2이상이면 최솟값 1이 된다.
	for (int i = 0; i < n; i++) {
		if (weight[i] > answer + 1) {
			break;
		}
		answer += weight[i];
	}

	cout << answer + 1 << endl;

	return 0;
}