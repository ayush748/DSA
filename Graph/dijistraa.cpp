#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    int src;
    cin>>src;
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int dis=front.first;
        int node=front.second;
        for(auto nbr:adj[node]){
            int nextNode=nbr.first;
            int edgeWt=nbr.second;
            if(dis+edgeWt < dist[nextNode]){

                dist[nextNode]=dis+edgeWt;

                q.push({dist[nextNode],nextNode});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }

}