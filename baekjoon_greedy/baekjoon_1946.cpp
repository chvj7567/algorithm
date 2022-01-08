#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::vector;
using std::sort;


bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	// 서류 심사 성적을 기준으로 정렬
	if (p1.first < p2.first) {
		return true;
	}
	return false;
}
int main() {
	// 테스트 케이스 수
	int test_case;
	// 케이스 별 선발 인원 수
	vector<int> select;
	// 선발 인원 수
	int cnt;
	// 지원자 수
	int num_of_applicants;
	// 성적 순위
	vector<pair<int, int>> rank;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 테스트 케이스 수 만큼 반복
	while (test_case > 0) {
		// 지원자 수 입력
		cin >> num_of_applicants;

		// 지원자 수 만큼 서류심사 성적과 면접 성적 입력
		for (int i = 0; i < num_of_applicants; i++) {
			int doc, inter;
			cin >> doc >> inter;
			rank.push_back(make_pair(doc, inter));
		}

		// 성적 순으로 정렬
		sort(rank.begin(), rank.end(), cmp);
		// 선발 인원 초기화
		cnt = 0;
		// 서류심사 성적을 기준으로 정렬 했으니
		// 면접 성적을 비교하기 위해
		// 서류심사 1등의 면접 성적 저장
		int maxRank = rank[0].second;

		// 면접 점수가 서류심사 앞 순위들보다
		// 높아야 뽑힐 수 있으므로
		// 앞 순위들의 최고 면접 성적을 기준으로
		// 비교하여 그 보다 높으면 선발
		for (int i = 0; i < rank.size(); i++) {
			// 각 점수 1등은 무조건 뽑히므로
			// >=을 붙여 서류심사 1등을 카운트에 포함
			if (maxRank >= rank[i].second) {
				maxRank = rank[i].second;
				cnt++;
			}
		}
		// 선발 인원 수 저장
		select.push_back(cnt);
		// 순위 초기화
		rank.clear();
		// 다음 테스트 케이스
		test_case--;
	}

	for (int cnt : select) {
		cout << cnt << endl;
	}

	return 0;
}