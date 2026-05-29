#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>pre(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>pre[i][j];
        }
    }
    unordered_map<int,vector<int>>adj;
    for(auto i:pre){
        int u=i[0];
        int v=i[1];
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
        auto front=q.front();
        cnt++;
        q.pop();
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(cnt==n){
        cout<<true;
    }else{
        cout<<false;
    }
    return 0;
}