#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>> &graph, vector<int> &color, int col, int n) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>> &graph, vector<int> &color, int m, int n) {
    if (node == n)
        return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, graph, color, col, n)) {
            color[node] = col;

            if (solve(node + 1, graph, color, m, n))
                return true;

            color[node] = 0;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> color(n, 0);

    if (solve(0, graph, color, m, n)) {
        cout << "Possible\n";
        for (int x : color)
            cout << x << " ";
    } else {
        cout << "Not Possible";
    }

    return 0;
}