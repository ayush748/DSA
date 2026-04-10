#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(int n,vector<vector<pair<int,int>>>&adj,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    vector<int>dist(n,1e9);
    dist[s]=0;
    pq.push({0,s});
    
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        if(dis>dist[node]){
            continue;
        }
        
        for(auto nbr:adj[node]){
            int n1=nbr.first;
            int d1=nbr.second;
            
            if(dis+d1<dist[n1]){
                dist[n1]=dis+d1;
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
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    int src;
    cin>>src;
    
    vector<int>ans=dijkstra(n,adj,src);
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}