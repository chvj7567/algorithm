#include <iostream>
#include <array>

using std::cout;
using std::endl;

void countingSort(std::array<int, 10>& arr) {
    std::array<int, 5> tmp = {};

    for (int i = 0; i < arr.size(); ++i) {
        tmp[arr[i] - 1]++;
    }

    int idx = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        while (tmp[i] != 0) {
            arr[idx++] = i + 1;
            --tmp[i];
        }
    }
}

int main() {
    std::array<int, 10> arr{ 1,4,3,2,2,4,5,5,1,2 };

    countingSort(arr);

    for (int i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}