#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isSafe(int x,int y,int n,int m){
    return ((x>=0 && x<n ) && (y>=0 && y<m));
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }
    int time=0;
    while(!q.empty()){
        auto frontnode=q.front();
        int x=frontnode.first.first;
        int y=frontnode.first.second;
        int mintime=frontnode.second;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nX=x+dx[i];
            int nY=y+dy[i];
            if(isSafe(nX,nY,n,m) && arr[nX][nY]==1){
                q.push({{nX,nY},mintime+1});
                arr[nX][nY]=2;
                time=max(mintime+1,time);
            }

        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                return -1;
            }
        }
    }
    return 0;
}