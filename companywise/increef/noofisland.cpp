#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int r,int c,vector<vector<char>>grid,vector<vector<bool>>vis){
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    q.push({r,c});
    vis[r][c]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int x=front.first;
        int y=front.second;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<n && !vis[newx][newy] && grid[newx][newy]=='1'){
                vis[newx][newy]=true;
                q.push({newx,newy});
            } 
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                bfs(i,j,grid,vis);
                cnt++;
            }
        }
    }
    
    

    return 0;
}