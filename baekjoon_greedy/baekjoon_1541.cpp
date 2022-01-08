#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void divide(string& expression, const char* del, vector<string>& plus_expression) {
    char* tmp = nullptr;
    char* token;

    // -�����ڷ� ������ ��(+�θ� �̷���� ��)�� ����
    token = strtok_s((char*)expression.c_str(), del, &tmp);

    plus_expression.push_back(token);

    while (token != NULL) {
        token = strtok_s(NULL, del, &tmp);
        if (token == NULL) {
            break;
        }
        plus_expression.push_back(token);
    }
}

int sum(string& plus_expression) {
    // ���ڸ� ���ڿ� ���·� ����
    vector<string> number;
    // ���� �ջ� ����
    int sum = 0;

    // +�� �����ڷ� ���� ����
    divide(plus_expression, "+", number);

    // ���ڿ� ���ڸ� int������ ��ȯ�Ͽ� �ջ�
    for (string n : number) {
        sum += stoi(n);
    }

    return sum;
}

int main() {
    // ǥ���� ����
    string expression;
    // + �����ڸ� �ִ� �� ����
    vector<string> plus_expression;
    // ���� ����
    vector<int> num;
    // ���� �� ����
    int result = 0;

    // ǥ���� �Է�
    cin >> expression;

    // -�� �����ڷ� ���� ����
    divide(expression, "-", plus_expression);

    // 1��°�� ���ڸ� ���� ���� �ְ� ���� ���� ���� ����
    // ���ڸ� ���� �״�� ���̸� ����� ���� ����
    result = sum(plus_expression[0]);

    // +�� ����� ���� ��� -�Ͽ� ���� �� ���
    for (int i = 1; i < plus_expression.size(); i++) {
        result -= sum(plus_expression[i]);
    }

    cout << result << endl;

    return 0;
}