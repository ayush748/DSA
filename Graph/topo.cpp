#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topoSort() {
        vector<int> indegree(V, 0);

        // Calculate indegree
        for (int i = 0; i < V; i++) {
            for (int neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;

        // Push all vertices with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        cout << "Topological Order: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
    }
};

int main() {

    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();

    return 0;
}