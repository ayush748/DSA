#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
void bfs(int rowX,int colY,vector<vector<char>>&arr,vector<vector<bool>>&visited){
    int n=arr.size();
    int m=arr[0].size();
    queue<pair<int,int>>q;
    q.push({rowX,colY});
    visited[rowX][colY]=true;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int x=front.first;
        int y=front.second;
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && !visited[newX][newY]==true && arr[newX][newY]=='1'){
                visited[newX][newY]=true;
                q.push({newX,newY});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    int cnt=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                bfs(i,j,arr,visited);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int n=0;
//     vector<bool>visited(n,false);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(!vis)
//         }
//     }
//     return 0;
// }