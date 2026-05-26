#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
bool dfs(int src,unordered_map<int,vector<int>>&mp,vector<int>&col,int newcol){
    col[src]=newcol;
    for(auto nbr:mp[src]){
        if(col[nbr]==col[src]){
            return false;
        }
        if(col[nbr]==-1){
            int colN=1-col[src];
            if(dfs(nbr,mp,col,colN)==false){
                return false;
            }
        }
    }
    return true;
}
bool bfs(int src,unordered_map<int,vector<int>>&mp,vector<int>&col){
    queue<int>q;
    q.push(src);
    col[src]=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto nbr:mp[front]){
            if(col[nbr]==col[front]){
                return false;
            }
            if(col[nbr]==-1){
                col[nbr]=1-col[front];
                q.push(nbr);
            }
        }
    }
    return true;
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
            if(arr[i][j] == 1 && i != j) {
                mp[i].push_back(j);
            }
        }
    }
    int ans=true;
    vector<int>col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            if(dfs(i,mp,col,0)==false){
                ans=false;
                break;
            }
        }
    }
    cout<<ans;

    return 0;
}