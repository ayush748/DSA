#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int l,int r){
    if(r-l <=1){
        return 0;
    }
    int res=INT_MAX;
    for(int i=l+1;i<r;i++){
        int cost=solve(arr,l,i)+solve(arr,i,r)+(arr[r]-arr[l]);
        res=min(res,cost);
    }
    return res;
}
int solvedp(vector<int>arr,int l,int r,vector<vector<int>>dp){
    if(r-l<=1){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int res=INT_MAX;
    for(int i=l+1;i<r;i++){
        int cost=solvedp(arr,l,i,dp)+solvedp(arr,i,r,dp)+arr[r]-arr[l];
        res=max(cost,res);
    }
    dp[l][r]=res;
    return dp[l][r];
}
int solve(vector<int>arr){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int l=n-1;l>=0;l--){
        for(int r=l+1;r<n;r++){
            int ans=INT_MAX;
            if(r-l<=1){
                dp[l][r]=0;
                continue; 
            }
            int ans=INT_MAX;
            for(int k=l+1;k<r;k++){
                int cost=dp[l][k]+dp[k][r]+(arr[r]-arr[l]);
                ans=min(ans,cost);
            }
            dp[l][r]=ans;
        }
    }
    return dp[0][n-1];
}
int main(){
    return 0;
}