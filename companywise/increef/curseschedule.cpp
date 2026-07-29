#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,vector<int>>adj;
    for(auto nbr:arr){
        int u=nbr[0];
        int v=nbr[1];
        adj[v].push_back(u);
    }
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto nbr:adj[i]){
            indegree[nbr]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cnt++;
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(cnt==n){
        return true;
    }else{
        return false;
    }
    return 0;
}