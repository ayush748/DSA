#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<int> key(V, INT_MAX);
    vector<bool> vis(V, false);

    key[0] = 0;
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (vis[u])
            continue;

        vis[u] = true;
        sum += wt;

        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];

            if (!vis[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return sum;
}