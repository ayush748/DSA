// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// using namespace std;
// int main(){
//     int n,e;
//     cin>>n>>e;
//     unordered_map<int,vector<pair<int,int>>>mp;
//     for(int i=0;i<n;i++){
//         int u,v,wt;
//         cin>>u>>v>>wt;
//         mp[u].push_back({v,wt});
//         mp[v].push_back({u,wt});
//     }
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     vector<int>vis(n,0);
//     int sum=0;
//     pq.push({0,0});
//     while(!pq.empty()){
//         auto it=pq.top();
//         pq.pop();
//         int wt=it.first;
//         int node=it.second;
//         if(vis[node]==1){
//             continue;
//         }
//         vis[node]=1;
//         sum=sum+wt;
//         for(auto it:mp[node]){
//             int a=it.first;
//             int w=it.second;
//             if(!vis[a]){
//                 pq.push({w,a});
//             }

//         }
//     }
//     cout<<sum;
//     return 0;
// }
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        mp[u].push_back({v,wt});
        mp[v].push_back({u,wt});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>vis(n,false);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        if(vis[node]){
            continue;
        }
        sum=sum+wt;
        vis[node]=true;

        for(auto nbr:mp[node]){
            int nn=nbr.first;
            int nw=nbr.second;
            if(vis[nn]==false){
                pq.push({nw,nn});
            }
        }
    }
    return 0;
}