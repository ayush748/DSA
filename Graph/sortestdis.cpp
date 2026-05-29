#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dis(n,-1);
    queue<int>q;
    int src=0;
    q.push(src);
    dis[src]=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto nbr:adj[front]){
            if(dis[front]+1<dis[nbr]){
                dis[nbr]=dis[front]+1;
                q.push(nbr);
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<dis.size();i++){
        if(dis[i]!=-1){
            ans.push_back(dis[i]);
        }
    }
    return 0;
}