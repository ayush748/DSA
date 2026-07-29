#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isSafe(int newX, int newY, map<pair<int,int>,bool> &visited, vector<vector<int>> &ans, int oldColor){
    if(newX >= 0 && newY >= 0 && newX < ans.size() && newY < ans[0].size() && ans[newX][newY] == oldColor && visited[{newX, newY}] == false){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int oldColor, int newColor, map<pair<int,int>, bool> &vis, vector<vector<int>> &ans, vector<vector<int>>& image, int sr, int sc)
    vis[{sr,sc}]=true;
    ans[sr][sc]=newcolor;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int newx=sr+dx[i];
        int newy=sc+dy[i];
        if(isSafe(newx,newy,vis,ans,oldcolor)){
            dfs(oldcolor,newcolor,vis,ans,image,);
        }
    }
}
int main(){
    int n;
    cin>>n;

    vector<vector<int>>image(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }
    int sr;
    int sc;
    int color;
    cin>>sr>>sc>>color;
    int oldcolor=image[sr][sc];
    int newcolor=color;
    map<pair<int,int>,bool>vis;
    vector<vector<int>>ans=image;
    dfs(oldcolor,newcolor,vis,ans,image,sr,sc);
    return 0;
}