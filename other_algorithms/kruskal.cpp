#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

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

class Edge {
public:
    std::pair<int, int> node;
    int distance;

    Edge(int a, int b, int d) {
        node.first = a;
        node.second = b;
        distance = d;
    }
    bool operator<(Edge& e) {
        return distance < e.distance;
    }
};

int main() {
    std::vector<Edge> v;

    v.push_back(Edge(0, 1, 15));
    v.push_back(Edge(1, 3, 28));
    v.push_back(Edge(1, 4, 10));
    v.push_back(Edge(4, 2, 12));
    v.push_back(Edge(4, 5, 5));
    v.push_back(Edge(0, 2, 3));
    v.push_back(Edge(0, 5, 11));
    v.push_back(Edge(2, 3, 17));
    v.push_back(Edge(3, 5, 32));

    std::sort(v.begin(), v.end());

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }

    int answer = 0;
    for (int i = 0; i < 9; ++i) {
        int a = v[i].node.first;
        int b = v[i].node.second;
        int d = v[i].distance;
        if (!(isSameParent(a, b))) {
            unionParent(a, b);
            answer += d;
        }
    }

    cout << answer << '\n';

    return 0;
}