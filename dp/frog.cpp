#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>arr){
    if(n==0){
        return 0;
    }
    int one=solve(n-1,arr)+abs(arr[n-1]-arr[n]);
    int two;
    if(n>1){
        two=solve(n-1,arr)+abs(arr[n-2]-arr[n]);
    }
    return min(one,two);
}
int solvedp(int n,vector<int>arr,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int one=solvedp(n-1,arr,dp)+abs(arr[n-1]-arr[n]);
    int two;
    if(n>1){
        two=solvedp(n-2,arr,dp)+abs(arr[n-2]-arr[n]);
    }
    dp[n]=min(one,two);
    return dp[n];

}
int solvetab(vector<int>arr){
    int n=arr.size();
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int one=dp[i-1]+abs(dp[i-1]-dp[i]);
        int two;
        if(i>1){
            two=dp[i-2]+abs(dp[i-2]-dp[i]);
        }
        dp[i]=min(one,two);
    }
    return dp[n];

}
int solveSpace(vector<int>arr){
    int n=arr.size();
    int prev=0;
    int curr=0;
    for(int i=1;i<n;i++){
        int one=prev+abs(arr[i-1]-arr[i]);
        int two;
        if(i>1){
            two=curr+abs(arr[i-2]-arr[i]);
        }
        int present=min(one,two);
        prev=curr;
        curr=present;
    }
    return prev;
}
int main(){
    vector<int>arr;
    int n=arr.size();
    int ans=solve(n,arr);
    return 0;
}