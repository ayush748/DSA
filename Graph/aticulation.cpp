#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int>& vis,
         vector<int>& tin, vector<int>& low,
         vector<int>& mark, vector<vector<int>>& adj) {

    vis[node] = 1;
    tin[node] = low[node] = timer++;

    int child = 0;

    for (auto it : adj[node]) {

        if (it == parent)
            continue;

        if (!vis[it]) {

            dfs(it, node, vis, tin, low, mark, adj);

            low[node] = min(low[node], low[it]);

            if (low[it] >= tin[node] && parent != -1) {
                mark[node] = 1;
            }

            child++;
        }
        else {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (child > 1 && parent == -1) {
        mark[node] = 1;
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> mark(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (mark[i] == 1) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    }
    else {
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}