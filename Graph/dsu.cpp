#include<iostream>
#include<vector>
using namespace std;

int find(int x, vector<int>& parent) {
    if(parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
    int px = find(x, parent);
    int py = find(y, parent);

    if(rank[px] > rank[py]) {
        parent[py] = px;
    }
    else if(rank[px] < rank[py]) {
        parent[px] = py;
    }
    else {
        parent[py] = px;
        rank[px]++;
    }
}

int main() {

    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    vector<int> parent(v);
    vector<int> rank(v, 0);

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < v; i++) {
        parent[i] = i;
    }

    for(int u = 0; u < v; u++) {
        for(auto v : adj[u]) {

            if(u < v) {
                Union(u, v, parent, rank);
            }
        }
    }

    for(int i = 0; i < v; i++) {
        cout << i << " -> " << parent[i] << endl;
    }

    return 0;
} 