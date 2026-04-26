#include<iostream>
#include<vector>
using namespace std;
long solve(vector<int>&arr,int i,int buy,int n){
    if(i>=n){
        return  0;
    }
    long profit=0;
    if(buy==0){
        profit=max(-arr[i]+solve(arr,i+1,1,n),0+solve(arr,i+1,0,n));
    }else{
        profit=max(arr[i]+solve(arr,i+2,0,n),0+solve(arr,i+1,1,n));
    }
    return profit;
}
int solvedp(vector<int>&arr,int i,int buy,int n,vector<vector<long>>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    long profit=0;
    if(buy==0){
        profit=max(-arr[i]+solvedp(arr,i+1,1,n,dp),0+solvedp(arr,i+1,0,n,dp));
    }else{
        profit=max(arr[i]+solvedp(arr,i+2,0,n,dp),0+solvedp(arr,i+1,1,n,dp));
    }
    dp[i][buy]=profit;
    return dp[i][buy];

}
long solvetab(vector<int>&arr){
    int n=arr.size();
    vector<vector<long>> dp(n+3, vector<long>(2, 0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            long profit=0;
            if(buy==0){
                profit=max(-arr[i]+dp[i+1][1],0+dp[i+1][0]);
            }else{
                profit=max(arr[i]+dp[i+2][0],dp[i+1][1]);
            }
            dp[i][buy]=profit;
        }
    }
    return dp[0][0];
}
int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int ans=solve(arr,0,0,k,n);
    return 0;
}