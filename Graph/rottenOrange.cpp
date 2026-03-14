#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(j);
        }
    }
    int minTime=0;
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }
    while(!q.empty()){
        auto frontnode=q.front();
        q.pop();
        int x=frontnode.first.first;
        int y=frontnode.first.second;
        int time=frontnode.second;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isSafe(nX,nY,n,m))
        }
    }
    return 0;
}