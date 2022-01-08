#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void changeCnt(int& money, int& cnt, int coin) {
    // 해당 금액에 동전의 최대 갯수를 구하고 그 만큼 가격을 뺌
    while (money >= coin) {
        money -= coin;
        cnt++;
    }
}
int main() {
    int money = 1000;
    int price = 0;
    int cnt = 0;

    // 물건 가격
    cin >> price;

    // 거스름돈
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