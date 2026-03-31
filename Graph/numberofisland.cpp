#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void bfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&visited){
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto val:mp[front]){
            
            if(!visited[val]){
                visited[val]=true;
                q.push(val);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && i!=j){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    
    vector<bool>visited(n,false);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i,mp,visited);
            cnt++;
        }
    }
    cout<<cnt<<endl;

}