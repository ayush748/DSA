#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void bfs(int src,vector<vector<int>>&edges,unordered_map<int,bool>&visited){
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        for(auto nbr:edges[frontnode]){
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
    vector<vector<int>>edge(v);
    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int cnt=0;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(i,edge,visited);
            cnt++;
        }
        
    }
    return 0;
}
