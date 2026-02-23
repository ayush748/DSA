#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<int>&coins,int amount){
    int n=coins.size();
    if(amount==0){
        return 0;
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int coin=coins[i];
        if(amount-coin>=0){
            int recAns=solve(coins,amount-coin);
            if(recAns!=INT_MAX){
                int ans=1+recAns;
                mini=max(ans,mini);
            }
        }
    }
    return mini;
}
int solve2(vector<int>&coins,int amount,vector<int>&dp){
    if(amount==0){
        return 0;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int coin=coins[i];
        if(amount-coins[i] >=0 ){
            int rec=solve2(coins,amount-coins[i],dp);
            if(rec!=INT_MAX){
                int ans=1+rec;
                mini=min(mini,ans);
            }
        }
    }
    dp[amount]=mini;
    return dp[amount];
}
int solve3(vector<int>&coins,int amount){
    int n=amount;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<=n;i++){
        int mini=INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i-coins[i]){
                int rec=dp[i-coins[j]];
                if(rec!=INT_MAX){
                    int ans=1+rec;
                    mini=min(mini,ans);
                }
            }
        }

        dp[i]=mini;

    }
}
int main(){
    return 0;
}