// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// using namespace std;
// bool isSafe(int x,int y,int n,int m){
//     if((x>=0 && x<n) && (y>=0 && y<n)){
//         return true;
//     }
//     return false;
// }
// int main(){
//     vector<vector<int>>arr={
//         {2,1,0},{1,1,0},{0,0,1}
//     };
//     int n=arr.size();
//     int m=arr[0].size();
//     queue<pair<pair<int,int>,int>>q;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==2){
//                 q.push({{i,j},0});
//             }
//         }
//     }
//     int time=0;
//     while(!q.empty()){
//         auto front=q.front();
//         int x=front.first.first;
//         int y=front.first.second;
//         int mintime=front.second;
//         int dx[]={-1,0,1,0};
//         int dy[]={0,1,0,-1};
//         for(int i=0;i<4;i++){
//             int nx=x+dx[i];
//             int ny=y+dy[i];
//             if(issafe(nx,ny) && arr[nx][ny]==1){
//                 q.push({{nx,ny},mintime+1});
//                 time=max(mintime+1,time);
//             }
//         }
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
bool isSafe(int x,int y,int n,int m){
    if((x>=0 && x<n) && (y>=0 && y<n)){
        return true;
    }else{
        return false;
    }
}
int main(){
    vector<vector<int>>arr={
        {2,1,0},{1,1,0},{0,0,1}
    };
    int n=arr.size();
    int m=arr.size();
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }
    int time=0;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int x=front.first.first;
        int y=front.first.second;
        int mintime=front.first.second;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(isSafe(nx,ny,n,m) && arr[nx][ny]==1){
                q.push({{nx,ny},mintime+1});
                arr[nx][ny]=2;
                time=max(mintime+1,time);
            }
        }

    }
    return 0;
}