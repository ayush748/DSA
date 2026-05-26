#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
bool dfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&vis,vector<bool>&rerec){
    vis[src]=true;
    rerec[src]=true;
    for(auto nbr:mp[src]){
        if(vis[nbr]==false && dfs(nbr,mp,vis,rerec)){
            return true;
        }else if(rerec[nbr]){
            return true;
        }
    }
    rerec[src]=false;
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
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                mp[i].push_back(j);
            }
        }
    }
    bool flag=false;
    vector<bool>vis(n,false);
    vector<bool>rerec(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i] && dfs(i,mp,vis,rerec)){
            flag=true;
            break;
        }
    }
    cout<<flag;
    return 0;
}