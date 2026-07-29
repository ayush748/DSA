#include<iostream>
#include<vector>
using namespace std;
int solve(int n){
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    int ans=solve(n-1)+solve(n-2);
    return ans;
}
int solvedp(int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=solvedp(n-1,dp)+solvedp(n-2,dp);
    dp[n]=ans;
    return dp[n];
}
int solvetab(int n){
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[0]=2;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int solve(int n){
    if(n<0){
        return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    int curr=1;
    int pre=1;
    int ans=0;
    for(int i=0;i<n;i++){
        ans=pre+curr;
        pre=curr;
        curr=ans;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans=solve(n);
    cout<<ans;
    return 0;
}