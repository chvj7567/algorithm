#include <iostream>
#include <array>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// 팀을 이룬 인원
int cnt = 0;
// 그래프로 나타낸 상태
std::array<int, 100001> graph;
// 방문 확인
std::array<bool, 100001> visited;
// 팀 확인
std::array<bool, 100001> team;

void dfs(int n) {
	// 방문 확인
	visited[n] = true;

	// 선택한 팀원
	int next = graph[n];

	// 선택한 팀원이 확인하지
	// 않았다면 재귀
	if (!visited[next]) {
		dfs(next);
	}
	// 선택한 팀원이 이미 확인했다면
	// (팀이 이루어졌다면)
	// 속한 팀이 없다면
	else if (!team[next]) {
		// 다시 싸이클을 돌아 인원 수 확인
		while (next != n) {
			++cnt;
			next = graph[next];
		}
		// 자기 자신 포함
		++cnt;
	}
	// 팀 확인
	// 팀을 이루지 못해도
	// 이루지 못한다는 걸 확인했다는 표시
	team[n] = true;
}

int main() {
	// c와 c++ 동기화 비활성화
	// cin과 cout 속도 향상
	std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 테스트 케이스 수
	int test_case;

	// 테스트 케이스 수 입력
	cin >> test_case;

	// 정답
	std::vector<int> answer;
	while (test_case > 0) {
		// 학생 수
		int students;
		// 학생 수 입력
		cin >> students;
		// 팀원 선택 입력
		for (int i = 1; i <= students; ++i) {
			cin >> graph[i];
		}
		// 팀 선택
		for (int i = 1; i <= students; ++i) {
			dfs(i);
		}
		// 전체 인원에서 팀을 이룬 사람 빼면
		// 팀에 속하지 못한 학생들의 수
		answer.push_back(students - cnt);

		// 다음 테스트 케이스를 위한 초기화
		cnt = 0;
		std::fill(visited.begin(), visited.end(), false);
		std::fill(team.begin(), team.end(), false);
		--test_case;
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}