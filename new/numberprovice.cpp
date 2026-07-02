#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void dfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>vis){
    vis[src]=true;
    for(auto nbr:mp[src]){
        if(!vis[nbr]){
            dfs(nbr,mp,vis);
        }
    }
}
// void bfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
//     queue<int>q;
//     q.push(src);
//     vis[src]=true;
//     while(!q.empty()){
//         auto front=q.front();
//         q.pop();
//         for(auto nbr:mp[front]){
//             if(!vis[nbr]){
//                 q.push(nbr);
//                 vis[nbr]=true;
//             }
//         }
//     }
// }
void bfs(int src,unordered_map<int,vector<int>>mp,vector<bool>&vis){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        for(auto nbr:mp[src]){
            if(!vis[nbr]){
                vis[nbr]=true;
                q.push(nbr);
            }
        }
    }
}
int main(){
    vector<vector<int>>arr={
        {1,1,0},{1,1,0},{0,0,1}
    };
    int n=arr.size();
    int m=arr[0].size();
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=j && arr[i][j]==1){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    vector<bool>vis(n,false);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,mp,vis);
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,mp,vis);
        }
    }
    cout<<cnt<<endl;
    return 0;
}