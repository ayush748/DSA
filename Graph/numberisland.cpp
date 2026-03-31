#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void solve(int src,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
    visited[src]=true;
    for(auto val:adj[src]){
        if(!visited[val]){
            solve(val,adj,visited);
        }
    }
}
int main(){
    vector<vector<int>> arr = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    int n=arr.size();
    int m=arr[0].size();
    unordered_map<int,vector<int>>adj;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            solve(i,adj,visited);
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}