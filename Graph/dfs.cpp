#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;

template<typename t>
class Graph{
public:
    unordered_map<t, list<pair<t,int>>> adjlist;

    void addedge(t u, t v, int wt, bool direction){
        adjlist[u].push_back({v, wt});
        if(!direction){   // undirected graph
            adjlist[v].push_back({u, wt});
        }
    }

    void bfs(t src , unordered_map<t,bool>& visited){
        queue<t> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            t frontnode = q.front();
            q.pop();

            cout << frontnode << " ";

            for(auto nbr : adjlist[frontnode]){
                t child = nbr.first;
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }

    void dfs(t src, unordered_map<t,bool>& visited){
        visited[src] = true;
        cout << src << " ";

        for(auto nbr : adjlist[src]){
            t child = nbr.first;
            if(!visited[child]){
                dfs(child, visited);
            }
        }
    }
};

int main(){

    Graph<int> g;

    // Component 1
    g.addedge(0,1,5,false);
    g.addedge(0,2,3,false);

    // Component 2
    g.addedge(3,4,2,false);

    unordered_map<int,bool> visited;

    cout << "BFS for Disconnected Graph: ";

    // 👇 FOR LOOP FOR DISCONNECTED
    for(int i = 0; i <= 4; i++){
        if(!visited[i]){
            g.bfs(i, visited);
        }
    }

    visited.clear();

    cout << "\nDFS for Disconnected Graph: ";

    for(int i = 0; i <= 4; i++){
        if(!visited[i]){
            g.dfs(i, visited);
        }
    }

    return 0;
}