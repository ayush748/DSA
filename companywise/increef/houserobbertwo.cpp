#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>arr,int i,int n){
    if(i>=n){
        return 0;
    }
    int l=arr[i]+solve(arr,i+2,n);
    int r=0+solve(arr,i+1,n);
    int ans=max(l,r);
    return ans;
}
int solvedp(vector<int>arr,int i,int n,vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int l=arr[i]+solvedp(arr,i+2,n,dp);
    int r=0+solvedp(arr,i+1,n,dp);
    int ans=max(l,r);
    dp[i]=ans;
    return dp[i];
}
int solvetab(vector<int>arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    vector<int>dp(n,0);
    dp[0]=arr[0];
    dp[1]=max(dp[0],dp[1]);
    for(int i=2;i<n;i++){
        int inc=arr[i]+dp[i-2];
        int exc=0+dp[i-1];
        dp[i]=max(inc,exc);
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=solve(arr,0,n-1);
    int r=solve(arr,1,n);
    int ans=max(l,r);
    cout<<ans;
    
    return 0;
}