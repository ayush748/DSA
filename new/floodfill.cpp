#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool isSafe(int newX, int newY, unordered_map<pair<int,int>,bool> &visited, vector<vector<int>> &ans, int oldColor){
        if(newX >= 0 && newY >= 0 && newX < ans.size() && newY < ans[0].size() && ans[newX][newY] == oldColor && visited[{newX, newY}] == false){
            return true;
        }
        else{
            return false;
        }
    }
void dfs(int oldColor, int newColor, unordered_map<pair<int,int>, bool> &visited, vector<vector<int>> &ans, vector<vector<int>>& image, int sr, int sc){
        // visited true for each cell/node
        visited[{sr,sc}] = true;
        ans[sr][sc] = newColor;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if(isSafe(newX, newY, visited, ans, oldColor)){
                dfs(oldColor, newColor, visited, ans, image, newX, newY);
            }
        }
    }
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int sr,sc,color;
    cin>>sr>>sc>>color;
    int oldcolor=arr[sr][sc];
    unordered_map<pair<int,int>,bool>mp;
    vector<vector<int>>ans=arr;
    dfs(oldcolor,color,mp,ans,arr,sr,sc);

    return 0;
}