#include <iostream>
#include <vector>
#include <string>
#include <regex>

using std::cin;
using std::cout;

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �׽�Ʈ ���̽� ��
    int test_case;
    // ���� ����
    std::string str;

    // �׽�Ʈ ���̽� �� �Է�
    cin >> test_case;

    // ����ǥ�������� ��Ģ ǥ��
    std::regex re("(100+1+|01)+");
    // ����
    std::vector<std::string> answer;

    while (test_case > 0) {
        // ���� �Է�
        cin >> str;

        // ��Ģ�� ��Ī�� �Ǹ� YES, �ȵǸ� NO
        if (std::regex_match(str, re)) {
            answer.push_back("YES");
        }
        else {
            answer.push_back("NO");
        }

        --test_case;
    }

    for (auto a : answer) {
        cout << a << '\n';
    }

    return 0;
}