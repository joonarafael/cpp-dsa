#include <bits/stdc++.h>
using namespace std;

void depthFirstSearch (int node, vector<vector<int>> &adjacencyList, vector<bool> &visited) {
    visited[node] = true;

    for (auto child : adjacencyList[node]) {
        if (visited[child] == false) {
            depthFirstSearch(child, adjacencyList, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    std::vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<int> roads;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            roads.push_back(i);
            depthFirstSearch(i, adjacencyList, visited);
        }
    }

    cout << roads.size() - 1 << endl;

    for (long unsigned int i = 0; i < roads.size() - 1; i++) {
        cout << 1 << " " << roads[i + 1] << endl;
    }

    return 0;
}