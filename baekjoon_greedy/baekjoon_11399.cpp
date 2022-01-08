#include <iostream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::multiset;

int main() {
    // 사람의 수와 모든 사람이 돈을 인출하는데
    // 걸리는 시간을 저장할 변수
    int people_num, tot_time = 0;

    // 각 사람이 돈을 인출하는데
    // 걸리는 시간을 저장할 변수
    multiset<int> time;

    // multiset iterator
    multiset<int>::iterator ms_iter;

    // 사람 수 입력
    cin >> people_num;

    // 각 사람의 돈 인출 시간 입력
    for (int i = 0; i < people_num; i++) {
        int num;
        cin >> num;
        time.insert(num);
    }

    // iterator 0번째 인덱스 지정
    ms_iter = time.begin();

    // 자동 정렬된 multiset 특성을 이용해
    // 첫번째 부터 각각 기다릴 사람의 수를 곱한다.
    // 각 걸리는 시간을 tot_time에 계속하여 더한다.
    for (int i = time.size(); i > 0; i--, ms_iter++) {
        tot_time += *ms_iter * i;
    }

    cout << tot_time << endl;

    return 0;
}