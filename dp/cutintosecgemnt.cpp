#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int x,int y,int z){
    if(n==0){
        return 0;
    }
    int x=solve(n-x,x,y,z)+1;
    int y=solve(n-y,x,y,z)+1;
    int z=solve(n-z,x,y,z)+1;
    int ans=max(x,max(y,z));
    return ans;
}
int solve2(int n,int x,int y,int z,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=solve2(n-x,x,y,z,dp)+1;
    int b=solve2(n-y,x,y,z,dp)+1;
    int c=solve2(n-z,x,y,z,dp)+1;
    int ans=max(a,max(b,c));
    dp[n]=ans;
    return dp[n];
}

int main(){
    return 0;
}