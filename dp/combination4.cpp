#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solveRec(vector<int>nums,int target){
    int n=nums.size();
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=nums[i]+solveRec(nums,target-nums[i]);
    }
    return ans;
}
int solvetab(vector<int>&nums,int target,vector<int>&dp){
    int n=nums.size();
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+solvetab(nums,target-nums[i],dp);
    }
    dp[target]=ans;
    return dp[target];
}
int solveTab(vector<int>nums,int target){
    int n=nums.size();
    if(target==0){
        return 0;
    }
    vector<int>dp(n+1,-1);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if((i-nums[j])>=0){
                dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}

int main(){
    return  0;
}