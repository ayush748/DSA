#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    dist[0][0]=0;
    priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
    >pq;

    int n=arr.size();
    int m=arr[0].size();

    dist[0][0]=0;
    pq.push({0,{0,0}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!pq.empty()){
        auto front=pq.top();
        pq.pop();

        int wt=front.first;
        int r=front.second.first;
        int c=front.second.second;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && arr[nr][nc]==1 && wt+1<dist[nr][nc]){
                dist[nr][nc]=1+wt;
                if((nr==n-1 && nc==m-1) ){
                    return wt+1;
                }
                pq.push({1+wt,{nr,nc}});
            }
        }

    }
    return 0;
}