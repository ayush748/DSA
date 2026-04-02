#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int src,vector<bool>&visited,vector<vector<int>>&adj){
    queue<pair<int,int>>q;
    q.push({src,-1});
    visited[src]=true;

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                visited[nbr]=true;
                q.push({nbr,node});
            }
            else if(nbr!=parent){
                return true;
            }
        }
    }
    return false;
}

bool isCheck(int n,vector<vector<int>>&adj){
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(i,visited,adj)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCheck(n,adj)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}