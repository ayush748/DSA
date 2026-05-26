#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool bfs(int src,unordered_map<int,vector<int>>&mp,vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int s=front.first;
        int p=front.second;
        for(auto nbr:mp[s]){
            if(nbr==p){
                continue;
            }
            if(vis[nbr]==false){
                vis[nbr]=true;
                q.push({nbr,s});
            }else if(nbr!=p && vis[nbr]){
                return true;
            }
        }
    }
    return false;
}
bool dfs(int src,vector<int>&vis,unordered_map<int,vector<int>>&mp,int parent){
    vis[src]=true;
    for(auto nbr:mp[src]){
        if(nbr==parent){
            continue;
        }
        if(vis[nbr]){
            return true;
        }
        if(dfs(nbr,vis,mp,src)){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i][j]==1){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    bool flag=false;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,vis,mp,-1)){
                flag=true;
                break;
            }
        }
    }
    cout<<flag;
    return 0;
}