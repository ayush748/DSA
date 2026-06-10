#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==0 || vis[i][j]){
        return 0;
    }
    vis[i][j]=true;
    int cnt=1;
    for(auto &d:dir){
        cnt += dfs(grid,i+d[0],j+d[1],vis);
    }
    return cnt;
}
int largestIsland(vector<vector<int>>&grid){
    n=grid.size();
    bool hasZero=false;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                hasZero=true;
                grid[i][j]=1;
                vector<vector<bool>> vis(n,vector<bool>(n,false));
                int largest=0;
                for(int x=0;x<n;x++){
                    for(int y=0;y<n;y++){
                        if(grid[x][y]==1 && !vis[x][y]){
                            largest=max(largest,dfs(grid,x,y,vis));
                        }
                    }
                }
                ans=max(ans,largest);
                grid[i][j]=0;
            }
        }
    }
    if(!hasZero){
        return n*n;
    }

    return ans;
}
int main(){
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<largestIsland(grid)<<endl;
    return 0;
}