#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solve(vector<int>arr,int i){
    if(i>=0){
        return 0;
    }
    int inc=arr[i]+solve(arr,i+2);
    int exc=0+solve(arr,i+1);
    int ans=max(inc,exc);
    return ans;
}
int solvedp(vector<int>arr,int i,vector<int>dp){
    if(i>=0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int inc=arr[i]+solvedp(arr,i+2,dp);
    int exc=0+solvedp(arr,i+1,dp);
    int ans=max(inc,exc);
    dp[i]=ans;
    return dp[i];
}
int solve(vector<int>arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    vector<int>dp(n+1,-1);
    dp[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        int tempans=0;
        if(i+2<n){
            tempans=dp[i+2];
        }
        int inc=arr[i]+tempans;
        int exc=0+dp[i+1];
        dp[i]=max(inc,exc);
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,0);
    return 0;
}