#include <iostream>
#include <array>

using std::cin;
using std::cout;

std::array<int, 6> arr;

int findParent(int n) {
    if (arr[n] == n) {
        return n;
    }

    return findParent(arr[n]);
}

void unionParent(int n1, int n2) {
    n1 = findParent(n1);
    n2 = findParent(n2);

    if (n1 < n2) {
        arr[n2] = n1;
    }
    else {
        arr[n1] = n2;
    }
}

bool isSameParent(int n1, int n2) {
    n1 = findParent(n1);
    n2 = findParent(n2);

    if (n1 == n2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }

    unionParent(0, 1);
    unionParent(1, 2);
    unionParent(3, 4);
    unionParent(4, 5);

    if (isSameParent(0, 2)) {
        cout << "연결 O" << '\n';
    }
    else {
        cout << "연결 X" << '\n';
    }

    if (isSameParent(1, 4)) {
        cout << "연결 O" << '\n';
    }
    else {
        cout << "연결 X" << '\n';
    }

    unionParent(1, 5);

    if (isSameParent(0, 2)) {
        cout << "연결 O" << '\n';
    }
    else {
        cout << "연결 X" << '\n';
    }

    if (isSameParent(1, 4)) {
        cout << "연결 O" << '\n';
    }
    else {
        cout << "연결 X" << '\n';
    }

    return 0;
}