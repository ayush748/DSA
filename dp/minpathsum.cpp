#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,vector<vector<int>>arr){
    if(i==0 && j==0){
        return arr[i][j];
    }
    if(i<0 || j<0){
        return 1e9;

    }
    int up=arr[i][j]+solve(i-1,j,arr);
    int down=arr[i][j]+solve(i,j-1,arr);
    return min(up,down);
}
int solveMemo(int i,int j,vector<vector<int>>arr,vector<vector<int>>dp){
    if(i==0 && j==0){
        return 0;
    }
    if(i<0 || j<0){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=arr[i][j]+solveMemo(i-1,j,arr,dp);
    int down=arr[i][j]+solveMemo(i,j-1,arr,dp);
    dp[i][j]=min(up,down);
    return dp[i][j];
}
int solvetab(int n,int m,vector<vector<int>>arr){
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j]=arr[i][j];
            }else{
                int up=arr[i][j];

                if(i>0){
                    up=up+dp[i-1][j];
                }else{
                    up=up+1e9;
                }

                int down=arr[i][j];
                if(j>0){
                    down=down+dp[i][j-1];
                }else{
                    down=down+1e9;
                }
                dp[i][j]=max(up,down);
            }

        }
    }
    return dp[n-1][m-1];
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
    int ans=solve(n-1,m-1,arr);
    return 0;
}