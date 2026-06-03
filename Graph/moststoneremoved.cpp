#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
void dfs(vector<vector<int>>&stones,int i,vector<bool>&vis){
    int n=stones.size();
    vis[i]=true;
    int r=stones[i][0];
    int c=stones[i][1];
    for(int j=0;j<n;j++){
        if((!vis[j]) && (stones[j][0]==r || stones[j][1]==c)){
            dfs(stones,j,vis);
        }
    }
}
int removeStones(vector<vector<int>>& stones) {
    int n=stones.size();
    vector<bool>vis(n,false);
    int grp=0;
    for(int i=0;i<n;i++){
        if(vis[i]==true){
            continue;
        }
        dfs(stones,i,vis);
        grp++;
    }
    return n-grp;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>stones(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>stones[i][j];
        }
    }
    vector<bool>vis(n,false);
    int grp=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        dfs(stones,i,vis);
        grp++;
    }
    cout<<(n-grp);
    return 0;
}