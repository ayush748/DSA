#include<iostream>
#include<vector>
using namespace std;
long solve(int i,int buy,vector<int>arr,int n){
    if(i==n){
        return 0;
    }
    long profit=0;
    if(buy){
        profit=max(-arr[i]+solve(i+1,0,arr,n),0+solve(i+1,1,arr,n));
    }else{
        profit=max(arr[i]+solve(i+1,1,arr,n),0+solve(i+1,0,arr,n));
    }
    return profit;
}
long solvedp(int i,int buy,vector<int>arr,int n,vector<vector<int>>dp){
    if(i==n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    long profit=0;
    if(buy){
        profit=max(-arr[i]+solvedp(i+1,0,arr,n,dp),0+solvedp(i+1,1,arr,n,dp));
    }else{
        profit=max(arr[i]+solvedp(i+1,1,arr,n,dp),0+solvedp(i+1,0,arr,n,dp));
    }
    dp[i][buy]=profit;
    return dp[i][buy];
}
long solve(vector<int>arr){
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[n][0]=dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            int profit=0;
            if(buy){
                profit=max(-arr[i]+dp[i+1][0],0+dp[i+1][1]);
            }else{
                profit=max(arr[i]+dp[i+1][1],0+dp[i+1][0]);
            }
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long ans=solve(0,1,arr,n);
    cout<<ans;
    return 0;
}