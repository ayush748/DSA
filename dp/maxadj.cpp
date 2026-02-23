#include<iostream>
#include<vector>
using namespace std;
int solve1(vector<int>arr,int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[0];
    }
    int inc=arr[n]+solve1(arr,n-2);
    int exc=solve1(arr,n-1);
    return max(inc,exc);
}
int solve2(vector<int>arr,int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int inc=solve2(arr,n-2,dp)+arr[n];
    int exc=solve2(arr,n-1,dp);
    return max(inc,exc);
}
int solve3(vector<int>arr,int n){
    vector<int>dp(n,0);
    dp[0]=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        int inc=dp[i-2]+arr[i];
        int exc=dp[i-1];
        dp[i]=max(inc,exc);
    }
    return dp[n-1];
}
int solve4(vector<int>arr){
    int n=arr.size();
    int prev1=arr[0];
    int prev2=0;
    for(int i=0;i<n;i++){
        int inc=prev2+arr[i];
        int exc=prev1;
        int ans=max(inc,exc);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;

}
int main(){
    vector<int>arr;
    int n;
    return 0;
}