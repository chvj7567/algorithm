#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main() {
    // ���� ����
    int rope_num;
    // ������ �ߵ�� �߷�
    vector<int> rope_weight;
    // �ִ� �߷�
    int max_weight = 0;

    // ���� ���� �Է�
    cin >> rope_num;

    // �� ������ �ߵ�� �߷� �Է�
    for (int i = 0; i < rope_num; i++) {
        int rope;
        cin >> rope;
        rope_weight.push_back(rope);
    }

    // �� ������ �ߵ�� �߷��� �������� �������� ����
    sort(rope_weight.begin(), rope_weight.end());

    // ���� ���� �߷��� �ߵ�� ������ �������� ������ŭ ���Ͽ�
    // �ִ� �߷��� ���Ѵ�.
    for (int i = 0; i < rope_weight.size(); i++) {
        int tmp_weight = rope_weight[i] * (rope_weight.size() - i);
        if (tmp_weight > max_weight) {
            max_weight = tmp_weight;
        }
    }

    cout << max_weight << endl;

    return 0;
}