#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::greater;

int minValue(vector<int>& a, const vector<int>& b) {
    // b 배열의 인덱스 사용 여부 체크
    bool check[50] = {};
    // 최종 값
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        // 최솟값 임시 지정
        int min = 10000;
        int tmp_index = {};
        // 각 값의 곱이 최소인 값을 지정 후
        // 지정된 해당 인덱스 번호를 저장한다.
        for (int j = 0; j < b.size(); j++) {
            if (min > a[i] * b[j] && !check[j]) {
                min = a[i] * b[j];
                tmp_index = j;
            }
        }
        // 저장된 인덱스 번호를 체크 표시 해준다.
        check[tmp_index] = true;
        // 곱을 최종 값에 더해준다.
        sum += a[i] * b[tmp_index];
    }

    return sum;
}

int main() {
    // 각 배열의 인덱스 수
    int number;

    // 배열 a, b
    vector<int> a, b;

    // 배열의 수 입력
    cin >> number;

    // a 배열 값 입력
    for (int i = 0; i < number; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    // b 배열 값 입력
    for (int i = 0; i < number; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    // a 배열 내림차순으로 정렬
    // 제일 큰 값부터 최솟값으로 처리해야
    // 최종 값이 최솟값이 된다.
    sort(a.begin(), a.end(), greater<int>());

    cout << minValue(a, b) << endl;

    return 0;
}