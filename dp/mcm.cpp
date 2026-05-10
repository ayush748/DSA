#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int mini=1e9;
    for(int k=i;k<j;k++){
        int step=arr[i-1]*arr[k]*arr[j]+solve(arr,i,j);
        if(step<mini){
            mini=step;
        }
    }
    return mini;
}
int solvedp(vector<int>arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+solvedp(arr,i,k,dp)+solvedp(arr,k+1,j,dp);
        if(mini<steps){
            steps=mini;
        }
    }
    dp[i][j]=mini;
    return dp[i][j];
}
int solve(vector<int>arr){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                if(steps<mini){
                    steps=mini;
                }
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
int main(){
    return 0;
}