#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr.push_back({u,v,wt});
    }
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto it:arr){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >pq;
    vector<int>dist(n,1e9);
    vector<int>cnt(n,0);
    pq.push({0,0});
    dist[0]=0;
    cnt[0]=1;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int adjnode=it.second;
        int currtime=it.first;
        for(auto nbr:adj[adjnode]){
            int adjN=nbr.first;
            int tim=nbr.second;
            if(currtime+tim<dist[adjN]){
                dist[adjN]=currtime+tim;
                cnt[adjN]=cnt[adjnode];
                pq.push({dist[adjN],adjN});
            }else if(currtime+tim == dist[adjnode]){
                cnt[adjN]=cnt[adjN]+cnt[adjnode];
            }
        }
    }
    cout<<dist[n-1];
    return 0;
}