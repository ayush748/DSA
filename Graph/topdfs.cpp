#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

template<typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);

        // Undirected graph
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void topoSortDFS(T node,
                     unordered_map<T, bool> &visited,
                     stack<T> &st) {

        visited[node] = true;

        for (auto neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                topoSortDFS(neighbour, visited, st);
            }
        }

        st.push(node);
    }

    void topoSort() {

        unordered_map<T, bool> visited;
        stack<T> st;

        for (auto i : adjList) {
            if (!visited[i.first]) {
                topoSortDFS(i.first, visited, st);
            }
        }

        cout << "Topological Order: ";

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }

        cout << endl;
    }
};

int main() {

    Graph<int> g;

    // Directed Graph
    g.addEdge(5, 2, 1);
    g.addEdge(5, 0, 1);
    g.addEdge(4, 0, 1);
    g.addEdge(4, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);

    g.topoSort();

    return 0;
}