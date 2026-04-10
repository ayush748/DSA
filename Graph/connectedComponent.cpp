#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
void bfs(int src,vector<vector<int>>&adj,unordered_map<int,bool>&visited){
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto nbr:adj[front]){
            if(!visited[nbr]){
                visited[nbr]=true;
                q.push(nbr);
            }
        }
    }
    
}
int main(){
    int v;
    cin>>v;
    vector<vector<int>>adj(v);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int d,e;
        cin>>d>>e;
        adj[d].push_back(e);
        adj[e].push_back(d);
    }
    unordered_map<int,bool>visited;
    int cnt=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(i,adj,visited);
            cnt++;
        }
    }

    return 0;
}