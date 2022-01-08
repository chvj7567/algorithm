#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void changeCnt(int& money, int& cnt, int coin) {
    // �ش� �ݾ׿� ������ �ִ� ������ ���ϰ� �� ��ŭ ������ ��
    while (money >= coin) {
        money -= coin;
        cnt++;
    }
}
int main() {
    int money = 1000;
    int price = 0;
    int cnt = 0;

    // ���� ����
    cin >> price;

    // �Ž�����
    money -= price;

    changeCnt(money, cnt, 500);
    changeCnt(money, cnt, 100);
    changeCnt(money, cnt, 50);
    changeCnt(money, cnt, 10);
    changeCnt(money, cnt, 5);
    changeCnt(money, cnt, 1);

    cout << cnt << endl;

    return 0;
}