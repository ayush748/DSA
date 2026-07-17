#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void bfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        cout<<front<<" ";
        for(auto nbr:adj[front]){
            if(!vis[nbr]){
                vis[nbr]=true;
                q.push(nbr);
            }
        }
    }
}
void dfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    for(auto nbr:adj[src]){
        if(!vis[nbr]){
            dfs(nbr,adj,vis);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int val;
            cin>>val;
            adj[i].push_back(val);
        }
    }
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,adj,vis);
        }
    }

    return 0;
}