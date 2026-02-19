#include<iostream>
#include<vector>
using namespace std;
int recursive(int n){
    if(n==0 || n==1){
        return n;
    }
    int ans=recursive(n-1)+recursive(n-2);
    return ans;
}
int topdownapproach(int n,vector<int>&dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=topdownapproach(n-1,dp)+topdownapproach(n-2,dp);
    return dp[n];
}
int bottomup(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    if(n==0){
        return dp[n];
    }
    dp[1]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int spaceopt(int n){
    int prev=0;
    if(n==0){
        return prev;
    }
    int curr=1;
    if(n==1){
        return curr;
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        ans=prev+curr;
        prev=curr;
        curr=ans;
    }
    return ans;
}
int maib(){
    int n;
    
    return 0;
}