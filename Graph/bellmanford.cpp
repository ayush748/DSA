#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(int n,int src,vector<vector<int>>&edges){
    vector<int>dist(n,1e9);
    dist[src]=0;
    
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            if(dist[u]!=1e9 && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    
    int src;
    cin>>src;
    
    vector<int>ans=solve(n,src,edges);
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}