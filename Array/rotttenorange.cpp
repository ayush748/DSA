#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isSafe(int x,int y,int n,int m){
    if((x>=0 && x<n) && (y>=0 && y<m)){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int,int>,int>>q;
    int mintime=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }
    queue<pair<pair<int,int>,int>>q;
    int time=0;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int x=front.first.first;
        int y=front.first.second;
        int mintime=front.second;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(isSafe(nx,ny,n,n) && arr[nx][ny]==1){
                q.push({{x,y},mintime+1});
                arr[nx][ny]=2;
                time=max(mintime+1,time);
            }
        }

    }
    return 0;
}