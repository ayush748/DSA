#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<pair<t,int>>>adjlist;
    void addEdge(t u,t v,int wt,bool direction){
        adjlist[u].push_back({v,wt});
        if(direction == 1){
            adjlist[v].push_back({u,wt});
        }
    }
    void printadjlist(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(auto nbr:i.second){
                cout<<nbr.first<<","<<nbr.second<<endl;
            }
        }
    }
    void bfs(t src)
    {
        unordered_map<t,bool>visited;
        queue<t>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            t node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:adjlist[node]){
                t child=nbr.first;
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
    }
    void dfs(t src,unordered_map<t,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbr:adjlist[src]){
            t child=nbr.first;
            if(!visited[src]){
                dfs(child,visited);
            }
        }
    }
    
};
int main(){
    
}