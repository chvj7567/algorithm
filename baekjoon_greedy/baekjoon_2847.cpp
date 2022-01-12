#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 레벨의 수와 정답
	int n, cnt = 0;
	// 각 레벨 별 점수
	std::vector<int> score;

	// 레벨 수 입력
	cin >> n;

	// 각 레벨 별 점수 입력
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		score.push_back(tmp);
	}

	// 큰 레벨 부터 작은 레벨 순으로
	// 아래 레벨이 큰 레벨 이상이면 1점 감소
	for (int i = n - 1; i > 0; --i) {
		while (score[i] <= score[i - 1]) {
			score[i - 1] -= 1;
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}