// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// using namespace std;
// void bfs(int src,vector<vector<int>>&adj,unordered_map<int,bool>&visited){
//     queue<int>q;
//     q.push(src);
//     visited[src]=true;
//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         for(auto nbr:adj[front]){
//             if(!visited[nbr]){
//                 visited[nbr]=true;
//                 q.push(nbr);
//             }
//         }
//     }
    
// }
// int main(){
//     int v;
//     cin>>v;
//     vector<vector<int>>adj(v);
//     int m;
//     cin>>m;
//     for(int i=0;i<m;i++){
//         int d,e;
//         cin>>d>>e;
//         adj[d].push_back(e);
//         adj[e].push_back(d);
//     }
//     unordered_map<int,bool>visited;
//     int cnt=0;
//     for(int i=0;i<v;i++){
//         if(!visited[i]){
//             bfs(i,adj,visited);
//             cnt++;
//         }
//     }

//     return 0;
// }
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void dfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
    vis[src]=true;
    for(auto nbr:mp[src]){
        if(!vis[nbr]){
            dfs(src,mp,vis);
        }
    }
}
void bfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        auto frontnode=q.front();
        q.pop();
        vis[frontnode]=true;
        for(auto nbr:mp[frontnode]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr]=true;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i].size();j++){
            if(i!=j && arr[i][j]==1){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    int cnt=0;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,mp,vis);
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}