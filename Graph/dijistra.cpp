#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int>dijistra(int n,vector<vector<pair<int,int>>>& adj,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>>pq;
    vector<int>dist(n,1e9);
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dis>dist[node]){
            continue;
        }
        for(auto nbr:adj[node]){
            int d1=nbr.first;
            int n1=nbr.second;
            if(d1+dis<dist[n1]){
                pq.push({dist[n1],n1});
                dist[n1]=d1;
            }
        }
    }
    return dist;
}
int main(){
    int n;
    cin>>n;

    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    int src;
    cin>>src;
    return 0;
}