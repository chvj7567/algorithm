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
    // 단어 수
    int num_of_word;
    // 각 단어 저장
    vector<string> word;
    // 알파벳이 차지하는 자릿수 단위들의 합
    array<int, 26> alpha = {};

    // 단어 수 입력
    cin >> num_of_word;

    // 각 단어 입력
    for (int i = 0; i < num_of_word; i++) {
        string s;
        cin >> s;
        word.push_back(s);
    }

    // 각 단어의 자릿수 단위만큼 합하여 저장
    for (int i = 0; i < word.size(); i++) {
        int num = 1;
        for (int j = word[i].size() - 1; j >= 0; j--) {
            alpha[word[i][j] - 'A'] += num;
            num *= 10;
        }
    }

    // 내림차순 정렬(각 알파벳이 차지하는 비중이 높은순으로)
    sort(alpha.data(), alpha.data() + 26, greater<int>());

    // 합의 최댓값
    int max_sum = 0;

    // 정렬되었으니 그 순서대로 9부터 차례대로 대입하여 합산
    for (int i = 0; i < 10; i++) {
        max_sum += alpha[i] * (9 - i);
    }

    cout << max_sum << endl;

    return 0;
}