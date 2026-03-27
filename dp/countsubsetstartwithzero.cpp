#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int i,int sum){
    if(i==0){
        if(arr[i]==0 && sum==0){
            return 2;
        }
        if(sum==0 || arr[0]==sum){
            return 1;
        }
        return 0;
    }
    int nottake=solve(arr,i-1,sum);
    int take=0;
    if(arr[i]<=sum){
        take=solve(arr,i-1,sum-arr[i]);
    }
    return take+nottake;
}
int solvedp(vector<int>&arr,int i,int sum ,vector<vector<int>>dp){
    if(i==0){
        if(arr[0]==0 && sum==0){
            return 2;
        }
        if(arr[0]==sum || sum==0){
            return 1;
        }
        return 1;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int nottake=solvedp(arr,i-1,sum,dp);
    int take=0;
    if(arr[i]<=sum){
        take=solvedp(arr,i-1,sum-arr[i],dp);
    }
    dp[i][sum]=take+nottake;
    return dp[i][sum];
}
int solvetab(vector<int>&arr,int sum){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(sum+1,0));
    if(arr[0]==0){
        dp[0][0]=2;
    }else{
        dp[0][0]=1;
    }
    if(arr[0]!=0 && arr[0]<=sum){
        dp[0][arr[0]]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            int nottake=dp[i][j];
            int take;
            if(arr[i]<=sum){
                take=dp[i][j-arr[i]];
            }
            dp[i][j]=take+nottake;
        }
    }
    return dp[n-1][sum];
}
int solvespace(vector<int>arr,int sum){
    int n=arr.size();
    vector<int>prev;
    vector<int>curr;
    if(arr[0]==0){
        prev[0]=2;
    }else{
        prev[0]=1;
    }
    if(arr[0]!=0 && arr[0]<=sum){
        prev[arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        curr[0]=arr[i]==0 ? 2*prev[0] : prev[0];
        for(int j=1;j<=sum;j++){
            int nottake=prev[j];
            int take=0;
            if(arr[i]<=j){
                take=prev[j-arr[i]];
            }
            curr[j]=take+nottake;
        }
        prev=curr;
    }

    return prev[sum];
}
int main(){
    return 0;
}