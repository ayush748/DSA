#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isSafe(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }

        }
    }
    int time=0;
    int n=grid.size();
    int m=grid.size();
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int x=front.first.first;
        int y=front.first.second;
        int mintime=front.second;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(isSafe(newx,newy,n,m) && grid[newx][newy]==1){
                q.push({{newx,newy},mintime+1});
                grid[newx][newy]=2;
                time=min(time,mintime+1);
            }
        }
    }
    return 0;
}