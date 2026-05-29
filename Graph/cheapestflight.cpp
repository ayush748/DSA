#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        mp[u].push_back({v,wt});
    }
    queue<pair<int,pair<int,int>>>q;
    int src,k,dis;
    cin>>src>>k>>dis;
    q.push({0,{src,0}});
    vector<int>dist(n,1e9);
    dist[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int steps=it.first;
        int node=it.second.first;
        int cost=it.second.second;
        if(steps>k){
            continue;
        }
        for(auto nbr:mp[node]){
            int adjnode=nbr.first;
            int edgewt=nbr.second;
            if(cost+edgewt < dist[adjnode] && steps<=k){
                dist[adjnode]=cost+edgewt;
                q.push({steps+1,{adjnode,dist[adjnode]}});
            }
        }
    }
    if(dist[dis] == 1e9) {
        cout << -1;
    }
    else {
        cout << dist[dis];
    }
    return 0;
}