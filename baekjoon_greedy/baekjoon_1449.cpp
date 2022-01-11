#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// 물이 새는 곳의 수, 테이프의 길이, 필요 테이프 수량
	int n, tape, cnt = 0;
	// 수리할 곳의 위치
	std::vector<int> repair;

	// 물이 새는 곳의 수와 테이프의 길이 입력
	cin >> n >> tape;

	// 수리할 곳의 위치 입력
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		repair.push_back(tmp);
	}

	// 오름차순 정렬
	std::sort(repair.begin(), repair.end());

	// 테이프의 위치를 잡고 테이프의 길이만큼
	// 연달아 붙일 수 있는 위치를 잡는다.
	// 처음 위치가 1이고 테이프의 길이가 3이라면
	// 붙일 수 있는 다음 위치는
	// (처음 위치  + 테이프의 길이) - 1 만큼이다.
	// <를 써서 -1은 포함되지 않게 했다.
	for (int i = 0; i < n; i++) {
		int tmp = repair[i];
		for (int j = i + 1; j < n; j++) {
			if (repair[j] < tmp + tape) {
				i++;
			}
		}
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}