#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs2(int node, vector<int>& vis, vector<int> adjT[]) {
    vis[node] = 1;

    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs2(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int>* adjT = new vector<int>[V];

    for (int i = 0; i < V; i++) {
        vis[i] = 0;

        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }

    return scc;
}

int main() {
    int n = 5;

    int edges[5][2] = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4}
    };

    vector<int>* adj = new vector<int>[n];

    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    cout << kosaraju(n, adj) << endl;

    return 0;
}