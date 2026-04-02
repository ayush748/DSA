#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

vector<int> shortestPath(int n,int m,vector<vector<int>>& edges){
    unordered_map<int,vector<pair<int,int>>> adj;

    for(auto &v:edges){
        int u=v[0];
        int x=v[1];
        int w=v[2];
        adj[u].push_back({x,w});
        adj[x].push_back({u,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    vector<int> par(n+1);

    for(int i=1;i<=n;i++){
        par[i]=i;
    }

    dist[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(d>dist[node]){
            continue;
        }

        for(auto &it:adj[node]){
            int adjNode=it.first;
            int edgW=it.second;

            if(d+edgW<dist[adjNode]){
                dist[adjNode]=d+edgW;
                par[adjNode]=node;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    if(dist[n]==INT_MAX){
        return {-1};
    }

    vector<int> path;
    int node=n;

    while(par[node]!=node){
        path.push_back(node);
        node=par[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());

    return path;
}

int main(){
    int n=5,m=6;
    vector<vector<int>> edges={
        {1,2,2},
        {2,5,5},
        {2,3,4},
        {1,4,1},
        {4,3,3},
        {3,5,1}
    };

    vector<int> ans=shortestPath(n,m,edges);

    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}