#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,vector<vector<int>>&arr){
    if(i>arr.size() || j>arr[0].size()){
        return 0;
    }
    if(arr[i][j]==0){
        return 0;
    }
    int r=solve(i,j+1,arr);
    int d=solve(i+1,j+1,arr);
    int b=solve(i+1,j,arr);
    return 1+min(r,min(d,b));
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                res=res+solve(i,j,arr);
            }
        }
    }
    return 0;
}