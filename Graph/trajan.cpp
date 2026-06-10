#include<iostream>
#include<vector>
using namespace std;
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>adj,vector<int>&tim,vector<int>&low,vector<vector<int>>bridges){
    vis[node]=1;
    tim[node]=low[node]=timer++;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        if(vis[it]==0){
            dfs(it,node,vis,adj,tim,low,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tim[node]){
                bridges.push_back({it,node});
            }
        }else{
            low[node]=min(low[node],low[it]);
        }
        
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(n));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>tin(n);
    vector<int>low(n);
    vector<vector<int>>bridges;
    dfs(0,-1,vis,adj,tin,low,bridges);
    for(auto &it:bridges){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}