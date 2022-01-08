#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main() {
    // 로프 갯수
    int rope_num;
    // 로프가 견디는 중량
    vector<int> rope_weight;
    // 최대 중량
    int max_weight = 0;

    // 로프 갯수 입력
    cin >> rope_num;

    // 각 로프가 견디는 중량 입력
    for (int i = 0; i < rope_num; i++) {
        int rope;
        cin >> rope;
        rope_weight.push_back(rope);
    }

    // 각 로프가 견디는 중량을 기준으로 오름차순 정렬
    sort(rope_weight.begin(), rope_weight.end());

    // 가장 적은 중량을 견디는 로프를 기준으로 갯수만큼 곱하여
    // 최대 중량을 구한다.
    for (int i = 0; i < rope_weight.size(); i++) {
        int tmp_weight = rope_weight[i] * (rope_weight.size() - i);
        if (tmp_weight > max_weight) {
            max_weight = tmp_weight;
        }
    }

    cout << max_weight << endl;

    return 0;
}