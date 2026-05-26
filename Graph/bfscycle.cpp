#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,e;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>indegree(n,0);
    for(int src=0;src<n;src++){
        for(auto nbr:adj[src]){
            indegree[nbr]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        auto front=q.front();
        count++;
        q.pop();
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }

    }
    if(count==n){
        cout<<false;// no cycle
    }else{
        cout<<true;
    }
    return 0;
}