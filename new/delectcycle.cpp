#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
bool dfs(int src,int p,vector<vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    for(auto nbr:adj[src]){
        if(!vis[nbr]){
            if(dfs(nbr,src,adj,vis)){
                return true;
            }
        }else if(nbr!=p){
            return false;
        }
    }
    return false;
}
bool check(int n,vector<vector<int>>adj){
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)){
                return true;
            }
        }
    }
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
    }
    bool ans=check(n,adj);
    cout<<ans;
    return 0;
}