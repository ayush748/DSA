#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution{
    public:

    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

    }

    int numIsland(vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
    }


    
};
int main(){
    Solution s;
    int n,m;
    cin>>n>>m;

    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<s.numIsland(arr);


    return 0;
}