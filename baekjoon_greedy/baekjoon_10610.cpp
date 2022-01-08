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
    // ��ü ���� ����
    string number;
    // 1�ڸ� ���� ����
    vector<int> one_number;
    // ���ڵ��� �� ����
    int sum = 0;

    // ���� �Է�
    cin >> number;

    // ���� ���ڿ��� int������ ��ȯ ��
    // �����ϰ� 1�ڸ� ���ڵ��� ���� ����
    for (int i = 0; i < number.length(); i++) {
        int n = number[i] - '0';
        one_number.push_back(n);
        sum += n;
    }

    // 30�� ��� ������ 3�� ����� �Ǵ��� Ȯ�� ��
    // �ȵǸ� -1 ��� �� ����
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // 1�ڸ� ���� �������� ����
    sort(one_number.begin(), one_number.end(), greater<int>());

    // ���� ���ڿ� ����
    number.clear();

    // ���ĵ� 1�ڸ� ���ڸ� ���ڿ��� ��ȯ
    for (int i : one_number) {
        number += to_string(i);
    }

    // 30�� ����� 3�� ����� ���ÿ� ������ �ڸ��� 0�̸� �ȴ�.
    // ��� �����ϰ� ��� ��� �����غô��� �¾Ҵ�.
    // ������ �ڸ��� �˻��Ͽ� 0���� Ȯ�� ��
    // �ƴϸ� -1����ϰ� ����
    if (number[number.length() - 1] != '0') {
        cout << -1 << endl;
        return 0;
    }

    cout << number << endl;

    return 0;
}