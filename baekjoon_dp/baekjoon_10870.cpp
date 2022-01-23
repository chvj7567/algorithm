#include <iostream>
#include <array>

using std::cin;
using std::cout;

// n번째 피보나치의 수
std::array<int, 21> dp = {};

int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // 저장된 값이 있다면
    // 저장된 dp값 반환
    if (dp[n] != 0) {
        return dp[n];
    }
    // dp에 값 저장 후 반환
    return dp[n] = fibo(n - 2) + fibo(n - 1);
}
int main() {
    // c와 c++ 동기화 비활성화
    // cin과 cout 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 정수
    int n;

    // 정수 입력
    cin >> n;

    cout << fibo(n) << '\n';

    return 0;
}