#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::array;
using std::sort;
using std::greater;

int main() {
    // �ܾ� ��
    int num_of_word;
    // �� �ܾ� ����
    vector<string> word;
    // ���ĺ��� �����ϴ� �ڸ��� �������� ��
    array<int, 26> alpha = {};

    // �ܾ� �� �Է�
    cin >> num_of_word;

    // �� �ܾ� �Է�
    for (int i = 0; i < num_of_word; i++) {
        string s;
        cin >> s;
        word.push_back(s);
    }

    // �� �ܾ��� �ڸ��� ������ŭ ���Ͽ� ����
    for (int i = 0; i < word.size(); i++) {
        int num = 1;
        for (int j = word[i].size() - 1; j >= 0; j--) {
            alpha[word[i][j] - 'A'] += num;
            num *= 10;
        }
    }

    // �������� ����(�� ���ĺ��� �����ϴ� ������ ����������)
    sort(alpha.data(), alpha.data() + 26, greater<int>());

    // ���� �ִ�
    int max_sum = 0;

    // ���ĵǾ����� �� ������� 9���� ���ʴ�� �����Ͽ� �ջ�
    for (int i = 0; i < 10; i++) {
        max_sum += alpha[i] * (9 - i);
    }

    cout << max_sum << endl;

    return 0;
}