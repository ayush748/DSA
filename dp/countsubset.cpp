#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int i,int sum){
    if(sum==0){
        return 1;
    }
    if(i==0){
        return arr[0]==sum;
    }
    int nottake=solve(arr,i-1,sum);
    int take=0;
    if(arr[i]<=sum){
        take=solve(arr,i-1,sum-arr[i]);
    }
    return take+nottake;
    
}
int solveMemo(vector<int>&arr,int i,int sum,vector<vector<int>>&dp){
    if(sum==0){
        return  1;
    }
    if(i==0){
        return arr[0]==sum;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int nottake=solveMemo(arr,i-1,sum,dp);
    int take=0;
    if(arr[i]<=sum){
        take=solveMemo(arr,i-1,sum-arr[i],dp);
    }
    return dp[i][sum]=take+nottake;
}
int solveTab(vector<int>&arr,int sum){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=sum){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take+nottake;
        }
    }
    return dp[n-1][sum];
}
int solveSpace(vector<int>& arr,int sum){
    int n=arr.size();
    vector<int> prev(sum+1,0),curr(sum+1,0);
    prev[0]=1;
    if(arr[0]<=sum){
        prev[arr[0]]=prev[arr[0]]+1;
    }
    for(int i=1;i<n;i++){
        curr[0]=1;
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
int solve(vector<int>&nums,int sum){
    int n=nums.size();
    vector<int>prev(sum+1,0);
    vector<int>curr(sum+1,0);
    prev[0]=1;
    if(nums[0]<=sum){
        prev[0]=prev[nums[0]]+1;
    }
    for(int i=0;i<n;i++){
        curr[0]=1;
        for(int j=1;j<=sum;j++){
            int nottake=prev[j];
            int take=0;
            if(nums[i]<=j){
                take=prev[j-nums[j]];
            }
            curr[j]=take+nottake;
        }
        prev=curr;
    }
    return prev[sum];

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans=solve(arr,n,target);
    cout<<ans;
    return 0;
}