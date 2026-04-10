// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// void dfs(int src,unordered_map<int,bool>&visited,vector<vector<int>>&adj){
//     visited[src]=true;
//     cout<<src<<" ";  
//     for(auto nbr:adj[src]){
//         if(!visited[nbr]){
//             dfs(nbr,visited,adj);
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
//         int c,d;
//         cin>>c>>d;
//         adj[c].push_back(d);
//         adj[d].push_back(c);
//     }
    
//     unordered_map<int,bool>visited;
    
//     for(int i=0;i<v;i++){
//         if(!visited[i]){
//             dfs(i,visited,adj);
//             cout<<endl;   
//         }
//     }
    
//     return 0;
// }
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void bfs(int src,vector<vector<int>>&adj,unordered_map<int,bool>&visited){
    queue<int>q;
    
    q.push(src);
    visited[src]=true;
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        cout<<front<<" ";  
        
        for(auto nbr:adj[front]){
            if(!visited[nbr]){
                visited[nbr]=true;
                q.push(nbr);
            }
        }
    }
}

int main(){
    int v;
    cin>>v;
    
    vector<vector<int>>adj(v);
    
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++){
        int d,e;
        cin>>d>>e;
        adj[d].push_back(e);
        adj[e].push_back(d);
    }
    
    unordered_map<int,bool>visited;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(i,adj,visited);
            cout<<endl;   
        }
    }

    return 0;
}