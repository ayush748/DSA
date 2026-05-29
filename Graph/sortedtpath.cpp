#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
void dfs(int src,unordered_map<int,vector<pair<int,int>>>mp,vector<bool>&vis,stack<int>&st){
    vis[src]=true;
    for(auto nbr:mp[src]){
        int front=nbr.first;
        if(!vis[front]){
            dfs(front,mp,vis,st);
        }
    }
    st.push(src);
}
int main(){
    int n,e;
    unordered_map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<e;i++){
        int u;
        int v;
        int wt;
        cin>>u>>v>>wt;
        mp[u].push_back({v,wt});
    }
    vector<bool>vis(n,false);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,mp,vis,st);
        }
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++){
        dist[i]=1e9;
    }
    while(!st.empty()){
        int front=st.top();
        st.pop();
        for(auto nbr:mp[front]){
            int v=nbr.first;
            int wt=nbr.second;
            if(dist[front]+wt<dist[v]){
                dist[v]=dist[front]+wt;
            }
        }
    }
    return 0;
}