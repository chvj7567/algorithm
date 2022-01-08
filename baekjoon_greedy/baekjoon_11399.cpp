#include <iostream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::multiset;

int main() {
    // ����� ���� ��� ����� ���� �����ϴµ�
    // �ɸ��� �ð��� ������ ����
    int people_num, tot_time = 0;

    // �� ����� ���� �����ϴµ�
    // �ɸ��� �ð��� ������ ����
    multiset<int> time;

    // multiset iterator
    multiset<int>::iterator ms_iter;

    // ��� �� �Է�
    cin >> people_num;

    // �� ����� �� ���� �ð� �Է�
    for (int i = 0; i < people_num; i++) {
        int num;
        cin >> num;
        time.insert(num);
    }

    // iterator 0��° �ε��� ����
    ms_iter = time.begin();

    // �ڵ� ���ĵ� multiset Ư���� �̿���
    // ù��° ���� ���� ��ٸ� ����� ���� ���Ѵ�.
    // �� �ɸ��� �ð��� tot_time�� ����Ͽ� ���Ѵ�.
    for (int i = time.size(); i > 0; i--, ms_iter++) {
        tot_time += *ms_iter * i;
    }

    cout << tot_time << endl;

    return 0;
}