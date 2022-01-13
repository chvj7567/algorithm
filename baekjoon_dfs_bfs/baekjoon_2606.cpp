#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;

// 네트워크 연결로
std::vector<int> connect[101];
// 감염 확인
std::array<int, 101> infection;

int virus(int target) {
	// 감염 체크
	infection[target] = true;
	int cnt = 0;

	// 네트워크 연결로를 통해 감염되지 않은
	// 컴퓨터 감염
	for (int i = 0; i < connect[target].size(); ++i) {
		int next = connect[target][i];
		if (!infection[next]) {
			infection[next] = true;
			++cnt;
			cnt += virus(next);
		}
	}

	return cnt;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 컴퓨터 수와 연결 네트워크 수
	int computer_num, network_num;

	// 컴퓨터 수와 네트워크 수 입력
	cin >> computer_num;
	cin >> network_num;

	// 네트워크 연결 입력
	for (int i = 0; i < network_num; ++i) {
		int a, b;
		cin >> a >> b;
		// 양방향
		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	// 오름차순 정렬
	for (int i = 0; i < computer_num; ++i) {
		std::sort(connect[i].begin(), connect[i].end());
	}

	cout << virus(1) << '\n';

	return 0;
}