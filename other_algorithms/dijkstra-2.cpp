#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

const int node = 6;

std::vector<std::pair<int, int>> graph[6];
std::array<int, 6> distance;

void dijkstra(int start) {
    std::priority_queue<std::pair<int, int>> pq;

    distance[start] = 0;

    pq.push({ distance[start], start });

    while (!pq.empty()) {
        int cur_d = -pq.top().first;
        int cur_n = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur_n].size(); ++i) {
            int next_n = graph[cur_n][i].first;
            int next_d = graph[cur_n][i].second + cur_d;

            if (next_d < distance[next_n]) {
                distance[next_n] = next_d;
                pq.push({ -next_d, next_n });
            }
        }
    }
}

int main() {
    graph[0].push_back({ 1, 4 });
    graph[0].push_back({ 3, 3 });
    graph[0].push_back({ 5, 1 });

    graph[1].push_back({ 0, 4 });
    graph[1].push_back({ 2, 5 });
    graph[1].push_back({ 4, 3 });

    graph[2].push_back({ 1, 5 });
    graph[2].push_back({ 3, 4 });
    graph[2].push_back({ 4, 3 });

    graph[3].push_back({ 0, 3 });
    graph[3].push_back({ 2, 4 });
    graph[3].push_back({ 5, 1 });

    graph[4].push_back({ 1, 3 });
    graph[4].push_back({ 2, 3 });

    graph[5].push_back({ 0, 1 });
    graph[5].push_back({ 3, 1 });

    std::fill(distance.begin(), distance.end(), 2e9);

    dijkstra(0);

    for (int i : distance) {
        cout << i << ' ';
    }

    return 0;
}