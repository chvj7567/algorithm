#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::greater;
using std::to_string;

int main() {
    // 전체 숫자 저장
    string number;
    // 1자리 숫자 저장
    vector<int> one_number;
    // 숫자들의 합 저장
    int sum = 0;

    // 숫자 입력
    cin >> number;

    // 숫자 문자열을 int형으로 변환 후
    // 저장하고 1자리 숫자들의 합을 구함
    for (int i = 0; i < number.length(); i++) {
        int n = number[i] - '0';
        one_number.push_back(n);
        sum += n;
    }

    // 30의 배수 이전에 3의 배수가 되는지 확인 후
    // 안되면 -1 출력 후 종료
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // 1자리 숫자 내림차순 정렬
    sort(one_number.begin(), one_number.end(), greater<int>());

    // 숫자 문자열 비우기
    number.clear();

    // 정렬된 1자리 숫자를 문자열로 변환
    for (int i : one_number) {
        number += to_string(i);
    }

    // 30의 배수는 3의 배수인 동시에 마지막 자리가 0이면 된다.
    // 라고 생각하고 몇가지 경우 대입해봤더니 맞았다.
    // 마지막 자리를 검사하여 0인지 확인 후
    // 아니면 -1출력하고 종료
    if (number[number.length() - 1] != '0') {
        cout << -1 << endl;
        return 0;
    }

    cout << number << endl;

    return 0;
}