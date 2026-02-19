#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction){
        adjList[u].push_back({v, wt});
        if(!direction){
            adjList[v].push_back({u, wt});
        }
    }

    void bfs(T src, unordered_map<T,bool>& visited){
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " -> ";

            for(auto nbr : adjList[frontNode]){
                T child = nbr.first;
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }
};

int main(){
    Graph<int> g;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt, 0); // undirected
    }

    unordered_map<int,bool> visited;

    for(auto i : g.adjList){
        int start = i.first;
        if(!visited[start]){
            g.bfs(start, visited);
            cout << endl;
        }
    }
    return 0;
}