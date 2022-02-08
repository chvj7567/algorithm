#include <iostream>
#include <array>
#include <cmath>

using std::cin;
using std::cout;

int main() {
    // c�� c++ ����ȭ ��Ȱ��ȭ
    // cin�� cout �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // �ֻ��� ����
    long long n;
    // �ֻ��� �� ���� ����
    std::array<int, 6> number = {};

    // �ֻ��� ���� �Է�
    cin >> n;

    // �ֻ��� �� ���� ���� �Է�
    for (int i = 0; i < 6; ++i) {
        cin >> number[i];
    }

    // �ֻ����� 1����� ��� �տ���
    // �ְ� ���� �ϳ��� ���� ����
    if (n == 1) {
        int max_one = 0;
        for (auto a : number) {
            max_one = std::max(max_one, a);
        }

        int answer = 0;
        for (auto a : number) {
            answer += a;
        }
        cout << answer - max_one << '\n';
        return 0;
    }

    // �� ���� �� �ּ� ���� ����
    int min_one = 51;
    for (auto a : number) {
        min_one = std::min(min_one, a);
    }

    // �پ��ִ� �� �� ������ ���� �ּ��� ���� ����
    int min_two = 101;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == j) {
                continue;
            }
            // ���ֺ��� 3�� ����
            if ((i == 0 && j == 5) || (i == 5 && j == 0)) {
                continue;
            }
            if ((i == 1 && j == 4) || (i == 4 && j == 1)) {
                continue;
            }
            if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
                continue;
            }
            min_two = std::min(min_two, number[i] + number[j]);
        }
    }

    // �پ��ִ� �� �� ������ ���� �ּ��� ���� ����
    int min_three = 151;
    std::array<int, 4> sum = {};

    sum[0] = std::min(number[0] + number[1] + number[2], number[0] + number[1] + number[3]);
    sum[1] = std::min(number[0] + number[2] + number[4], number[0] + number[3] + number[4]);
    sum[2] = std::min(number[1] + number[2] + number[5], number[1] + number[3] + number[5]);
    sum[3] = std::min(number[2] + number[4] + number[5], number[3] + number[4] + number[5]);

    for (auto a : sum) {
        min_three = std::min(min_three, a);
    }

    // �ֻ����� n3���� �ξ��� ��
    // �ֻ��� �� �𼭸�                (�� ��) : 4
    // �ֻ��� �� ��                    (�� ��) : (n - 2) * 4
    // �ֻ����� �� �𼭸� �� �� ����   (�� ��) : (n - 2) * (n - 2)
    // �ֻ����� ������ �� �𼭸�       (�� ��) : (n - 1) * 4
    // �ֻ����� �� �𼭸� ����         (�� ��) : (n - 2) * (n - 1) * 4
    std::array<long long, 5> part = {};
    long long one = min_one;
    long long two = min_two;
    long long three = min_three;

    part[0] = (two * 4) * (n - 1);
    part[1] = (three) * 4;
    part[2] = one * (n - 2) * (n - 1) * 4;
    part[3] = (two) * (n - 2) * 4;
    part[4] = one * std::pow(n - 2, 2);

    long long answer = 0;
    for (auto a : part) {
        answer += a;
    }

    cout << answer << '\n';

    return 0;
}