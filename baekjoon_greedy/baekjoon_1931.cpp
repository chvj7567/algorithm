#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

// ������ �ð��� ���� ������ ����
// ������ �ð��� ���ٸ� ���� �ð��� ���� ������ ����
bool cmp(const pair<int, int>& prev, const pair<int, int>& next) {
    if (prev.second == next.second) {
        return prev.first < next.first;
    }
    else {
        return prev.second < next.second;
    }
}

// ȸ�� ������ �ִ� ������ ��ȯ�ϴ� �Լ�
int maxNumOfMeeting(vector<pair<int, int>>& meeting_time) {
    // ȸ�� ������ �ִ� ���� �� ȸ���� ���� �ð��� ����
    int max_num = 0;
    int finish_time = 0;

    sort(meeting_time.begin(), meeting_time.end(), cmp);

    // ȸ�Ǹ� �ϴϾ� �����ϸ鼭 ������ ȸ�� �ð���
    // ������ �ð��� ���� ȸ�� �ð��� ���� �ð���
    // ���ϸ鼭 ����
    for (auto time : meeting_time) {
        if (finish_time <= time.first) {
            finish_time = time.second;
            max_num++;
        }
    }

    return max_num;
}

int main() {
    // ȸ�� ���� �ð��� �� �ð� ����
    vector<pair<int, int>> meeting_time;

    // ȸ���� ��
    int meeting_num;

    // ȸ�� �� �Է�
    cin >> meeting_num;

    // �� ȸ���� ���۽ð��� �� �ð� �Է�
    for (int i = 0; i < meeting_num; i++) {
        int start_time, finish_time;
        cin >> start_time >> finish_time;
        meeting_time.push_back(make_pair(start_time, finish_time));
    }

    cout << maxNumOfMeeting(meeting_time) << endl;

    return 0;
}