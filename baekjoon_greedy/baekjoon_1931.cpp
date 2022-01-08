#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

// 끝나는 시간이 빠른 순으로 정렬
// 끝나는 시간이 같다면 시작 시간이 빠른 순으로 정렬
bool cmp(const pair<int, int>& prev, const pair<int, int>& next) {
    if (prev.second == next.second) {
        return prev.first < next.first;
    }
    else {
        return prev.second < next.second;
    }
}

// 회의 가능한 최대 갯수를 반환하는 함수
int maxNumOfMeeting(vector<pair<int, int>>& meeting_time) {
    // 회의 가능한 최대 수와 각 회의의 시작 시간을 저장
    int max_num = 0;
    int finish_time = 0;

    sort(meeting_time.begin(), meeting_time.end(), cmp);

    // 회의를 하니씩 배정하면서 배정된 회의 시간의
    // 끝나는 시간과 다음 회의 시간의 시작 시간을
    // 비교하면서 배정
    for (auto time : meeting_time) {
        if (finish_time <= time.first) {
            finish_time = time.second;
            max_num++;
        }
    }

    return max_num;
}

int main() {
    // 회의 시작 시간과 끝 시간 저장
    vector<pair<int, int>> meeting_time;

    // 회의의 수
    int meeting_num;

    // 회의 수 입력
    cin >> meeting_num;

    // 각 회의의 시작시간과 끝 시간 입력
    for (int i = 0; i < meeting_num; i++) {
        int start_time, finish_time;
        cin >> start_time >> finish_time;
        meeting_time.push_back(make_pair(start_time, finish_time));
    }

    cout << maxNumOfMeeting(meeting_time) << endl;

    return 0;
}