#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// 동생을 잡기까지의 최소 시간 기록
std::array<int, 100001> minTime;
// 다음 이동의 상대 위치
std::array<int, 3> next = { -1, 1, 2 };

int find(int n, int k) {
	// 두 위치가 동일하다면 동생을 잡았으므로 종료
	if (n == k) {
		return 0;
	}

	// 동생을 잡는데 걸리는 시간의 모든 경우
	std::vector<int> v;

	// 큐에 현재 위치 저장 후 체크
	std::queue<int> q;
	minTime[n] = 1;
	q.push(n);

	while (!q.empty()) {
		// 현재 위치
		int cur_n = q.front();
		q.pop();

		// 동생을 잡았으면 반복문 종료
		if (cur_n == k) {
			break;
		}

		// 움직일 수 있는 3가지 경우
		for (int i = 0; i < 3; ++i) {
			// 움직일 경우 위치
			int next_n = cur_n;
			// 순간이동을 할 경우 위치
			if (i == 2) {
				next_n *= next[i];
			}
			// 앞 뒤로 이동할 경우 위치
			else {
				next_n += next[i];
			}
			// 전체 위치를 벗어나지 않고 한번 지나친 위치가 아니라면
			if (!(next_n < 0 || next_n>100000) && !minTime[next_n]) {
				// 다음 위치에 경과 시간 1 추가
				minTime[next_n] = minTime[cur_n] + 1;
				q.push(next_n);
				// 동생을 잡았을 경우의 시간 저장
				if (next_n == k) {
					v.push_back(minTime[next_n]);
				}
			}
		}
	}

	// 동생을 잡기까지의 여러 시간들 오름차순 정렬
	std::sort(v.begin(), v.end());

	// 최소 시간 - 1(처음 1은 그 위치에 있었다는 걸 표기하기 위해서므로)
	return v[0] - 1;
}
int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 수빈이의 위치와 동생의 위치
	int n, k;

	// 수빈이의 위치와 동생의 위치 입력
	cin >> n >> k;

	cout << find(n, k) << '\n';

	return 0;
}