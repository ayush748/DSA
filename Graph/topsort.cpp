#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename t>
class Graph{
    public:
    unordered_map<t,list<pair<t,int>>>adjlist;
    void addEdge(t u,t v,int wt,bool direction){
        adjlist[u].push_back({v,wt});
        if(direction){
            adjlist[v].push_back({u,wt});
        }
    }
    void bfs(t src,unordered_map<t,t>visited){
        unordered_map<T,T>parent;
        queue<t>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            t frontnode=q.front();
            q.pop();
            for(auto nbr:adjlist[frontnode]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    parent[child]=frontnode;
                }else if(!visited[child] && nbr==parent[frontnode]){
                    continue;
                }else if(visited[child] && child!=parent[frontnode]){
                    return true;
                }
            }
        }
        return false;


    }
    void dfs(t src,unordered_map<t,bool>&visited,int parent){
        visited[src]=true;
        for(auto nbr:adjlist[frontnode]){
            if(!visited[nbr]){
                bool ans=dfs(nbr,visited,src);
                if(ans==true){
                    return true;
                }
            }else if(visited[nbr] && nbr==parent){
                continue;
            }else if(visited[nbr] && child!=parent){
                return false;
            }
        }
        return false;
    }
};
int main(){
    return 0;
}
