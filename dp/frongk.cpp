// frog k jump
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int n,int k){
    if(n==0){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int ansk=solve(arr,n-i,k)+abs(arr[n]-arr[n-i]);
            ans=min(ans,ansk);
        }
    }
    return ans;
}
int solvedp(vector<int>arr,int n,int k,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int jump=solvedp(arr,n-i,k,dp)+abs(arr[i]-arr[i-1]);
            ans=min(ans,jump);
        }
    }
    dp[n]=ans;
    return dp[n];
}
int solvetab(vector<int>arr,int k){
    int n=arr.size();
    if(n==0){
        return  0;
    }
    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int ans=dp[i-j]+abs(arr[i]-arr[i-j]);
                dp[i]=min(dp[i],ans);
            }
        }
    }
    return dp[n-1];
}

int main(){
    vector<int>arr;
    int n=arr.size();
    int k;
    int ans=solve(arr,n-1,k);
    return 0;
}