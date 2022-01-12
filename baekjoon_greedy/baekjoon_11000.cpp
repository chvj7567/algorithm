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
	// 강의 수
	int n;
	// 강의실 배정을 위한 변수
	std::priority_queue<int, std::vector<int>, std::greater<int>> finish_time;
	// 강의 시간
	std::vector<std::pair<int, int>> time;

	// 강의 수 입력
	cin >> n;

	// 강의 시간 입력
	for (int i = 0; i < n; ++i) {
		int start_time;
		int finish_time;
		cin >> start_time >> finish_time;
		time.push_back(std::make_pair(start_time, finish_time));
	}

	// 강의 시작 시간이 빠른 순으로 정렬
	std::sort(time.begin(), time.end());

	// 첫 번째 강의는 자동 배정이므로 끝나는 시간 저장
	finish_time.push(time[0].second);

	// 끝나는 시간을 기준으로 다음 강의 시작 시간이
	// 끝나는 시간 이상이면 같은 강의실에 배정
	// 해당하지 않으면 다른 강의실에 배정하여
	// 우선순위 큐로 관리
	for (int i = 1; i < n; ++i) {
		if (finish_time.top() <= time[i].first) {
			finish_time.pop();
		}
		finish_time.push(time[i].second);
	}

	cout << finish_time.size() << '\n';

	return 0;
}