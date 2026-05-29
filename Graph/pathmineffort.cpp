#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    pq.push({0,{0,0}});
    dist[0][0]=0;
    int dr[]={-1,-1,0,1,1,1,0,-1};
    int dc[]={0,1,1,1,0,-1,-1,-1};
    int ans=-1;
    while(!pq.empty()){
        auto front=pq.top();
        pq.pop();
        int dis=front.first;
        int r=front.second.first;
        int c=front.second.second;
        if(r==n-1 && c==m-1){
            ans=dis;
            break;
        }
        for(int i=0;i<8;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m ){
                int newd=max(abs(arr[r][c]-arr[nr][nc]),dis);
                if(newd<dist[nr][nc]){
                    dist[nr][nc]=newd;
                    pq.push({newd,{nr,nc}});
                }
            }
        }

    }
    return 0;
}