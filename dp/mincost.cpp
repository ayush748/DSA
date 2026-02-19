#include<iostream>
#include<vector>
using namespace std;
// recursive approach
int solve1(vector<int>&arr,int n){
    if(n==0){
        return arr[0];
    }
    if(n==1){
        return arr[1];
    }
    int ans=arr[n]+min(solve1(arr,n-1),solve1(arr,n-2));
    return ans;
}
int solve2(vector<int>arr,int n,vector<int>&dp){
    if(n==0){
        return arr[0];
    }
    if(n==1){
        return arr[1];
    }

    dp[n]=arr[n]+min(solve2(arr,n-1,dp),solve2(arr,n-2,dp));
    return dp[n];
}
int solve3(int n,vector<int>&arr){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    vector<int>dp(n+1);
    dp[0]=arr[0];
    dp[1]=arr[1];
    for(int i=2;i<n;i++){
        dp[i]=arr[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int solve4(int n,vector<int>&arr){
    int prev2=arr[0];
    int prev1=arr[1];
    for(int i=2;i<n;i++){
        int curr=arr[0]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n+1,-1);
    int ans=solve3(n,arr);
    cout<<ans;
    return 0;
}