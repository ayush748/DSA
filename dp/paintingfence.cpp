#include<iostream>
#include<vector>
using namespace std;
int solverec(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*k;
    }
    int ans=(k-1)*(solverec(n-1,k)+solverec(n-2,k));
    return ans;
}
int solvetop(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return k*k;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=(k-1)*(solvetop(n-1,k,dp)+solvetop(n-2,k,dp));
    dp[n]=ans;
    return dp[n];
}
int solvebottom(int n,int k){
    if(n==1){
        return k;
    }
    vector<long long>dp(n+1);
    dp[1]=k;
    dp[2]=k*k;
    for(int i=3;i<=n;i++){
        dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
int solveso(int n,int k){
    if(n==1){
        return k;
    }
    long long p2=k;
    long long p1=k*k;
    for(int i=3;i<=n;i++){
        long long curr=(k-1)*(p1+p2);
        p2=p1;
        p1=curr;
    }
    return p1;
}
int main(){
    return 0;
}