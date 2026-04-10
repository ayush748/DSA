#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> solve(int n,int src,vector<vector<pair<int,int>>>&adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    vector<int>dist(n,1e9);
    dist[src]=0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        if(distance>dist[node]){
            continue;
        }
        
        for(auto nbr:adj[node]){
            int n1=nbr.first;
            int d1=nbr.second;
            
            if(distance+d1<dist[n1]){
                dist[n1]=distance+d1;
                pq.push({dist[n1],n1});
            }
        }
    }
    
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>>adj(n);
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int src;
    cin>>src;
    
    vector<int>ans=solve(n,src,adj);
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}