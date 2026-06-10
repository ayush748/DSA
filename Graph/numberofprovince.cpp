// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// void solve(int src,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
//     visited[src]=true;
//     for(auto val:adj[src]){
//         if(!visited[val]){
//             solve(val,adj,visited);
//         }
//     }
// }
// int main(){
//     vector<vector<int>> arr = {
//         {1,1,0},
//         {1,1,0},
//         {0,0,1}
//     };
//     int n=arr.size();
//     int m=arr[0].size();
//     unordered_map<int,vector<int>>adj;
//     vector<bool>visited(n,false);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==1){
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             solve(i,adj,visited);
//             cnt++;
//         }
//     }
//     cout<<cnt<<endl;

//     return 0;
// }

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void dfs(int& src,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
    vis[src]=true;
    for(auto nbr:mp[src]){
        if(!vis[nbr]){
            dfs(nbr,mp,vis);
        }
    }
}
void bfs(int src,unordered_map<int,vector<int>>mp,vector<int>vis){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        vis[front]=true;
        for(auto val:mp[front]){
            if(!vis[val]){
                q.push(val);
                vis[val]=true;
            }
        }
    }


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
            if(arr[i][j]==1 && i!=j){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    int cnt=0;
    vector<bool>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,mp,vis);
            cnt++;
        }
    }

    return 0;
}