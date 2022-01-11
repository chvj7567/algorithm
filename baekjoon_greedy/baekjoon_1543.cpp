#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// 문서의 내용과 단어
	std::string doc, word;
	// 검색 위치 지정
	int check_first = -1;
	// 같은 단어 확인, 정담
	int check_cnt = 0, answer = 0;

	// 문서의 내용과 단어 입력
	getline(cin, doc, '\n');
	getline(cin, word, '\n');

	// 문서와 단어 비교
	for (int i = 0; i < doc.size(); i++) {
		for (int j = 0; j < word.size(); j++) {
			// 단어의 첫자가 문서의 첫 비교 위치를 제외한
			// 문서의 내용과 같을 때 해당 위치 기억
			// 단어가 일부만 같을 시 이 위치에서 시작
			if (check_first == -1 && j != 0 && doc[i] == word[0]) {
				check_first = i;
			}
			// 단어가 같다면 단어의 수만큼 카운팅하고
			// 문서의 위치도 함께 이동
			if (doc[i] == word[j]) {
				check_cnt++;
				i++;
			}
			else {
				// 단어가 다르고 중간에 시작 위치를 갖고 있다면
				// 시작 위치를 넘겨주고 -1로 초기화
				if (check_first != -1) {
					i = check_first - 1;
					check_first = -1;
				}
				// 카운팅 초기화
				check_cnt = 0;
				break;
			}
		}
		// 단어 카운팅이 단어의 수가 같다면 완전히 같음을 확인
		// 문서의 위치는 1이 또 증가하므로 미리 1감소
		// 카운팅과 시작 위치 초기화
		if (check_cnt == word.size()) {
			answer++;
			i--;
			check_cnt = 0;
			check_first = -1;
		}
	}

	cout << answer << endl;

	return 0;
}