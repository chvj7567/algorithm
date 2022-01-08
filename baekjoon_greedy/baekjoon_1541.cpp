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

    // -연산자로 구분한 식(+로만 이루어진 식)을 저장
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
    // 숫자를 문자열 형태로 저장
    vector<string> number;
    // 식의 합산 저장
    int sum = 0;

    // +를 구분자로 식을 나눔
    divide(plus_expression, "+", number);

    // 문자열 숫자를 int형으로 변환하여 합산
    for (string n : number) {
        sum += stoi(n);
    }

    return sum;
}

int main() {
    // 표현식 저장
    string expression;
    // + 연산자만 있는 식 저장
    vector<string> plus_expression;
    // 숫자 저장
    vector<int> num;
    // 최종 값 저장
    int result = 0;

    // 표현식 입력
    cin >> expression;

    // -를 구분자로 식을 나눔
    divide(expression, "-", plus_expression);

    // 1번째는 숫자만 있을 수도 있고 식이 있을 수도 있음
    // 숫자면 숫자 그대로 식이면 계산한 값을 저장
    result = sum(plus_expression[0]);

    // +만 계산한 식을 모두 -하여 최종 값 계산
    for (int i = 1; i < plus_expression.size(); i++) {
        result -= sum(plus_expression[i]);
    }

    cout << result << endl;

    return 0;
}