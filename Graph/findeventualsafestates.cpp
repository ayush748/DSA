#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>&arr){
    int n=arr.size();
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(auto nbr:arr[i]){
            adj[nbr].push_back(i);
        }
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
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
bool dfs(int src,vector<vector<int>>&arr,vector<bool>&vis,vector<bool>&re){
    vis[src]=true;
    re[src]=true;
    for(auto nbr:arr[src]){
        if(vis[nbr]==false && dfs(nbr,arr,vis,re)){
            return false;
        }else if(re[nbr]==true){
            return true;
        }
    }
    re[src]=false;
    return false;
}
int main(){
    int n;
    vector<vector<int>>arr(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        while(m--){
            int val;
            cin>>val;
            arr[i].push_back(val);
        }
    }
    vector<bool>vis(n,false);
    vector<bool>re(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,arr,vis,re);
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(re[i]=false){
            ans.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}