#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>& g){
    int n=g.size(), m=g[0].size();
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));
    
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    
    while(!q.empty()){
        auto it=q.front(); q.pop();
        int r=it.first.first;
        int c=it.first.second;
        int d=it.second;
        
        dist[r][c]=d;
        
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                vis[nr][nc]=1;
                q.push({{nr,nc},d+1});
            }
        }
    }
    
    return dist;
}

int main(){
    vector<vector<int>> g{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
    
    auto ans=solve(g);
    
    for(auto &i:ans){
        for(auto &j:i) cout<<j<<" ";
        cout<<"\n";
    }
}