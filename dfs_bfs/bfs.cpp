#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

vector<int> v[11];
bool visited[11];

void bfs(int node) {
    queue<int> box;

    visited[node] = true;
    cout << node << " ";

    box.push(node);

    while (!box.empty()) {
        int next = box.front();

        box.pop();

        for (int i = 0; i < v[next].size(); i++) {
            int n = v[next][i];

            if (!visited[n]) {
                visited[n] = true;
                cout << n << " ";
                box.push(n);
            }
        }
    }

}
int main() {
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(4);

    v[2].push_back(1);

    v[3].push_back(1);
    v[3].push_back(6);
    v[3].push_back(7);

    v[4].push_back(1);
    v[4].push_back(5);
    v[4].push_back(8);

    v[5].push_back(4);

    v[6].push_back(3);

    v[7].push_back(3);

    v[8].push_back(4);
    v[8].push_back(9);
    v[8].push_back(10);

    v[9].push_back(8);
    v[9].push_back(10);

    v[10].push_back(8);
    v[10].push_back(9);

    bfs(1);

    return 0;
}