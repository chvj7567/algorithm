#include <iostream>
#include <array>

using std::cin;
using std::cout;

const int node = 6;

std::array<std::array<int, 6>, 6> arr{
    0,4,2e9,3,2e9,1,
    4,2e9,5,2e9,3,2e9,
    2e9,5,2e9,4,3,2e9,
    3,2e9,4,2e9,2e9,1,
    2e9,3,3,2e9,2e9,2e9,
    1,2e9,2e9,1,2e9,2e9,
};
std::array<bool, 6> visited;
std::array<int, 6> distance;

int minDistanceIndex() {
    int min = 2e9;
    int idx = -1;
    for (int i = 0; i < node; ++i) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            idx = i;
        }
    }

    return idx;
}

void dijkstra(int start) {
    for (int i = 0; i < node; ++i) {
        distance[i] = arr[start][i];
    }

    distance[start] = 0;
    visited[start] = true;

    for (int i = 0; i < node - 2; ++i) {
        int cur = minDistanceIndex();

        visited[cur] = true;
        for (int j = 0; j < node; ++j) {
            if (!visited[j]) {
                distance[j] = std::min(distance[j], distance[cur] + arr[cur][j]);
            }
        }
    }
}

int main() {
    dijkstra(0);

    for (int i : distance) {
        cout << i << ' ';
    }

    return 0;
}