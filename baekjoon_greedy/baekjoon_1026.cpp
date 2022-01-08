#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::greater;

int minValue(vector<int>& a, const vector<int>& b) {
    // b �迭�� �ε��� ��� ���� üũ
    bool check[50] = {};
    // ���� ��
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        // �ּڰ� �ӽ� ����
        int min = 10000;
        int tmp_index = {};
        // �� ���� ���� �ּ��� ���� ���� ��
        // ������ �ش� �ε��� ��ȣ�� �����Ѵ�.
        for (int j = 0; j < b.size(); j++) {
            if (min > a[i] * b[j] && !check[j]) {
                min = a[i] * b[j];
                tmp_index = j;
            }
        }
        // ����� �ε��� ��ȣ�� üũ ǥ�� ���ش�.
        check[tmp_index] = true;
        // ���� ���� ���� �����ش�.
        sum += a[i] * b[tmp_index];
    }

    return sum;
}

int main() {
    // �� �迭�� �ε��� ��
    int number;

    // �迭 a, b
    vector<int> a, b;

    // �迭�� �� �Է�
    cin >> number;

    // a �迭 �� �Է�
    for (int i = 0; i < number; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    // b �迭 �� �Է�
    for (int i = 0; i < number; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    // a �迭 ������������ ����
    // ���� ū ������ �ּڰ����� ó���ؾ�
    // ���� ���� �ּڰ��� �ȴ�.
    sort(a.begin(), a.end(), greater<int>());

    cout << minValue(a, b) << endl;

    return 0;
}