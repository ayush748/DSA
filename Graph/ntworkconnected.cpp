#include<iostream>
#include<vector>
using namespace std;
int find(int x,vector<int>parent){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x],parent);
}
void Union(int x,int y,vector<vector<int>>adj,vector<int>&parent,vector<int>&rank){
    int px=find(x,parent);
    int py=find(y,parent);

    if(px==py){
        return ;
    }
    if(parent[px]<parent[py]){
        parent[px]=py;
    }else if(parent[py]<parent[px]){
        parent[py]=py;
    }else{
        parent[py]=px;
        rank[px]++;
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>parent(n);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int u=0;u<n;u++){
        for(auto nbr:adj[u]){
            if(u<nbr){
                Union(u,nbr,parent,rank);
            }
        }
    }
    return 0;
}