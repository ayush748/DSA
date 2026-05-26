// #include<iostream>
// #include<vector>
// #include<queue>
// #include<unordered_map>
// using namespace std;
// int main(){
//     int n,e;
//     cin>>n>>e;
//     unordered_map<int,vector<int>>mp;
//     for(int i=0;i<e;i++){
//         int u,v;
//         cin>>u>>v;
//         mp[u].push_back(v);
//     }
//     vector<int>indegree(n,0);
//     for(int i=0;i<n;i++){
//         for(auto nbr:mp[i]){
//             indegree[nbr]++;
//         }
//     }
//     queue<int>q;
//     for(int i=0;i<n;i++){
//         if(indegree[i]==0){
//             q.push(i);
//         }
//     }
//     vector<int>res;
//     while(!q.empty()){
//         int front=q.front();
//         res.push_back(front);
//         q.pop();
//         for(auto nbr:mp[front]){
//             indegree[nbr]--;
//             if(indegree[nbr]==0){
//                 q.push(nbr);
//             }
//         }
//     }
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
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
    }
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto nbr:mp[i]){
            indegree[nbr]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        auto front=q.front();
        res.push_back(front);
        q.pop();
        for(auto nbr:mp[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }

    }
    if(res.size()!=n){
        cout<<"Cycle Present";
    }
    else{
        for(auto it:res){
            cout<<it<<" ";
        }
    }
    return 0;
}