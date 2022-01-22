#include <iostream>
#include <queue>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;

void radixSort(std::array<int, 10>& arr) {
    std::array<std::queue<int>, 10> q;
    int max_value = 0, max_digit = 1;
    int digit = 1;

    for (int i : arr) {
        max_value = std::max(max_value, i);
    }

    while (max_digit <= max_value) {
        max_digit *= 10;
    }
    max_digit /= 10;

    while (max_digit >= digit) {
        for (int i = 0; i < arr.size(); ++i) {
            int idx = (arr[i] % (digit * 10)) / digit;
            q[idx].push(arr[i]);
        }

        int idx = 0;
        for (int i = 0; i < q.size(); ++i) {
            while (!q[i].empty()) {
                arr[idx++] = q[i].front();
                q[i].pop();
            }
        }

        digit *= 10;
    }
}

int main() {
    std::array<int, 10> arr{ 10,2,5,4,3,1,6,8,7,9 };

    radixSort(arr);

    for (int i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}