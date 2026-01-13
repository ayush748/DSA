#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph {
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction) {
        adjList[u].push_back({v, wt});
        if (!direction) {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for (auto it : adjList) {
            cout << it.first << " -> ";
            for (auto nbr : it.second) {
                cout << "(" << nbr.first << "," << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    void bfsGraph(T src) {
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();

            cout << frontNode << " ";

            for (auto nbr : adjList[frontNode]) {
                T child = nbr.first;
                if (!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
        cout << endl;
    }

    void dfsTraversal(T src, unordered_map<T, bool>& visited) {
        visited[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src]) {
            T child = nbr.first;
            if (!visited[child]) {
                dfsTraversal(child, visited);
            }
        }
    }
};

int main() {
    Graph<int> g;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt, 1); // directed
    }

    g.printAdjList();
    g.bfsGraph(0);

    unordered_map<int, bool> visited;
    g.dfsTraversal(0, visited);

    return 0;
}
