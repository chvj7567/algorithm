#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	// 세로와 가로 길이
	int height, width;
	// 정답
	int answer = 0;

	// 세로와 가로 길이 입력
	cin >> height >> width;

	// 높이가 0 또는 1인 경우
	// 못 움직이므로 처음 방문한 1칸이 끝
	// 높이가 2인 경우
	// 2가지 패턴 밖에 못 움직이므로
	// 최대 3번 움직일 수 있음
	// 높이가 3이상인 경우(그 이상은 다 같다.)
	// 가로 길이에 따라
	// 4가지 패턴으로 움직일 수 있음
	// 4가지 패턴 사용 후에는 가로로
	// 제일 적게 움직이는(가로로 1칸)
	// 패턴만 사용하여 계산
	switch (height) {
	case 0:
	case 1:
		answer = 1;
		break;
	case 2:
		switch (width) {
		case 0:
		case 1:
		case 2:
			answer = 1;
			break;
		case 3:
		case 4:
			answer = 2;
			break;
		case 5:
		case 6:
			answer = 3;
			break;
		default:
			answer = 4;
			break;
		}
		break;
	default:
		switch (width) {
		case 0:
		case 1:
			answer = 1;
			break;
		case 2:
			answer = 2;
			break;
		case 3:
			answer = 3;
			break;
		case 4:
		case 5:
		case 6:
			answer = 4;
			break;
		case 7:
			answer = 5;
			break;
		default:
			answer = 5;
			width -= 7;
			answer += width;
			break;
		}
		break;
	}

	cout << answer << endl;

	return 0;
}