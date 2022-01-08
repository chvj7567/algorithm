#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

vector<int> v[11];
bool visited[11];
bool visited2[11];

void dfs(int node) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < v[node].size(); i++) {
        dfs(v[node][i]);
    }
}

void dfs2(int node) {
    stack<int> box;

    visited2[node] = true;
    cout << node << " ";

    box.push(node);

    while (!box.empty()) {
        bool check = false;

        int next = box.top();

        for (int i = 0; i < v[next].size(); i++) {
            int n = v[next][i];

            if (!visited2[n]) {
                visited2[n] = true;
                check = true;
                box.push(n);
                cout << n << " ";
                break;
            }
        }
        if (!check) {
            box.pop();
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

    dfs(1);
    cout << endl;

    dfs2(1);

    return 0;
}