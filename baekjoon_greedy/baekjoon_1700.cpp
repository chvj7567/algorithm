#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 멀티탭 구멍 수와 전기 용품 수, 정답
	int n, k, answer = 0;
	// 사용할 제품 순서
	std::vector<int> use;
	// 멀티탭
	std::array<int, 101> multitap = {};

	// 멀티탭 구멍 수와 전기 용품 수 입력
	cin >> n >> k;

	// 사용할 제품 순서 입력
	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;
		use.push_back(tmp);
	}

	for (int i = 0; i < k; ++i) {
		// 해당 기기가 사용 중인지 확인
		bool check = false;
		for (int j = 0; j < n; ++j) {
			if (multitap[j] == use[i]) {
				check = true;
				break;
			}
		}
		// 사용 중이면 다음 제품으로
		if (check) {
			continue;
		}
		// 사용 중이 아니라면
		else {
			// 임시 인덱스 저장
			int tmp_idx;
			// 멀티탭에 빈 자리가 있는지 확인
			for (int j = 0; j < n; ++j) {
				if (multitap[j] == 0) {
					check = true;
					tmp_idx = j;
					break;
				}
			}
			// 멀티탭에 빈 자리가 있다면 사용한다.
			// 사용 하고 다음 제품으로
			if (check) {
				multitap[tmp_idx] = use[i];
				continue;
			}
			// 멀티탭에 빈 자리가 없다면
			else {
				// 가장 나중에 사용할 제품을 고르기 위한 벡터
				std::vector<std::pair<int, int>> later;
				for (int j = 0; j < n; ++j) {
					// 가장 나중에 사용할 제품을 고르기 위한 카운팅
					int cnt = 0;
					if (multitap[j] != 0) {
						for (int l = i; l < k; ++l) {
							if (multitap[j] == use[l]) {
								break;
							}
							cnt++;
						}
						later.push_back(std::make_pair(cnt, j));
					}
				}

				// 가장 나중에 사용할 인덱스가 0 인덱스에 오도록 정렬
				std::sort(later.begin(), later.end(), std::greater<std::pair<int, int>>());

				// 가장 나중에 사용할 제품을 찾아서 다음 제품으로 변경
				for (int j = 0; j < n; ++j) {
					if (multitap[j] == multitap[later[0].second]) {
						multitap[j] = use[i];
						++answer;
					}
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}