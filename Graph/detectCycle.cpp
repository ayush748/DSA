#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

bool dfs(int src,int p,vector<vector<int>>&adj,vector<bool>&visited){
    visited[src]=true;
    for(auto s:adj[src]){
        if(!visited[s]){
            if(dfs(s,src,adj,visited)){
                return true;
            }
        }
        else if(s!=p){
            return true;
        }
    }
    return false;
}
bool check(int v,vector<vector<int>>adj){
    vector<bool>visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited)){
                return true;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}