// #include<iostream>
// #include<vector>
// using namespace std;
// int solve(vector<int>arr,int curr,int prev){
//     if(curr>=arr.size() ){
//         return 0;
//     }
//     int inc=0;
//     if(prev!=-1 || arr[curr]!=arr[prev]){
//         inc=1+solve(arr,curr+1,curr);
//     }
//     int exc=0+solve(arr,curr+1,prev);
//     return max(inc,exc);
// }
// int solvedp(vector<int>arr,int curr,int prev,vector<vector<int>>& dp){
//     if(curr>=arr.size()){
//         return 0;
//     }
//     if(dp[curr][prev+1]!=-1){
//         return dp[curr][prev+1];
//     }
//     int inc=0;
//     if(prev==-1 || arr[curr]>arr[prev]){
//         inc=1+solvedp(arr,curr+1,curr,dp);
//     }
//     int exc=0+solvedp(arr,curr+1,prev,dp);
//     dp[curr][prev+1]=max(inc,exc);
//     return dp[curr][prev];
// }
// int solvetab(vector<int>arr){
//     int n=arr.size();
//     vector<vector<int>>dp(n,vector<int>(n+1,0));
//     for(int i=n-1;i>=0;i--){
//         for(int j=i-1;j>=0;j--){
//             int inc=0;
//             if(j==-1 || arr[i]>arr[j]){
//                 inc=1+dp[i+1][i];
//             }
//             int exc=0+dp[i+1][j+1];
//             dp[i][j+1]=max(inc,exc);
//         }
//     }
//     return dp[0][0];
// }
// int solveusingre(vector<int>&nums,int curr,int prev)
// {
//     if(curr>=nums.size())
//     {
//         return 0;
//     }
//     int include=0;
//     if(prev==-1 || nums[curr]>nums[prev])
//     {
//         include=1+solveusingre(nums,curr+1,curr);
//     }
//     int exclude=0+solveusingre(nums,curr+1,prev);
//     int ans=max(include,exclude);
//     return ans;
// }
// int solveusingtop(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp)
// {
//     if(curr>=nums.size())
//     {
//         return 0;
//     }
//     if(dp[curr][prev+1] !=-1)
//     {
//         return dp[curr][prev+1];
//     }
//     int include=0;
//     if(prev==-1 || nums[curr]>nums[prev])
//     {
//         include=1+solveusingtop(nums,curr+1,curr,dp);
//     }
//     int exclude=0+solveusingtop(nums,curr+1,prev,dp);
//     dp[curr][prev+1]=max(include,exclude);
//     return dp[curr][prev+1];
// }
// int solveusingtabulation(vector<int>num)
// {
//     int n=num.size();
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     for(int i=n-1;i>=0;i--)
//     {
//         for(int j=i-1;j>=-1;j--)
//         {
//             int include=0;
//             if(j==-1 || num[i]>num[j])
//             {
//                 include=1+dp[i+1][i];
//             }
//             int exclude=0+dp[i+1][j+1];
//             dp[i][j+1]=max(include,exclude);
//         }
//     }
//     return dp[0][0];
// }
// int solveusingso(vector<int>&nums)
// {
//     int n=nums.size();
//     vector<int>currRow(n+1,0);
//     vector<int>nextRow(n+1,0);
//     for(int curr_index=n-1;curr_index>=0;curr_index--)
//     {
//         for(int j=curr_index-1;j>=-1;j--)
//         {
//             int include=0;
//             if(j==-1 || nums[curr_index]>nums[j])
//             {
//                 include=1+nextRow[curr_index+1];
//             }
//             int exclude=0+nextRow[j+1];
//             currRow[j+1]=max(include,exclude);
//         }
//         nextRow=currRow;
//     }
//     return nextRow[0];
// }
// int solveusingbs(vector<int>&nums)
// {
//     vector<int>ans;
//     ans.push_back(nums[0]);
//     for(int i=1;i<nums.size();i++)
//     {
//         if(nums[i]>ans.back())
//         {
//             ans.push_back(nums[i]);
//         }
//         else
//         {
//             int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
//             ans[index]=nums[i];
//         }
       
//     }
//     return ans.size(); 
// }
// int solveusingbs(vector<int>&nums)
// {
//     vector<int>ans;
//     ans.push_back(nums[0]);
//     for(int i=1;i<nums.size();i++)
//     {
//         if(nums[i]>ans.back())
//         {
//             ans.push_back(nums[i]);
//         }
//         else
//         {
//             int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
//             ans[index]=nums[i];
//         }
       
//     }
//     return ans.size(); 
// }
// int solvebs(vector<int>&arr){
//     int n=arr.size();
//     vector<int>ans;
//     ans.push_back(arr[0]);
//     for(int i=1;i<arr.size();i++){
//         if(arr[i]>ans.back()){
//             ans.push_back(arr[i]);
//         }else{
//             int i=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
//             ans[i]=arr[i];
//         }
//     }

//     return  ans.size();

// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//     int ans=solvedp(arr,0,-1,dp);
//     cout<<ans;
//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int curr,int prev){
    if(curr>=arr.size()){
        return 0;
    }
    int inc=0;
    if(prev==-1 || arr[curr]>arr[prev]){
        inc=1+solve(arr,curr+1,curr);
    }
    int exc=0+solve(arr,curr+1,curr);
    return max(inc,exc);
}
int solvedp(vector<int>arr,int curr,int prev,vector<vector<int>>&dp){
    if(curr>=arr.size()){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    int inc=0;
    if(prev==-1 || arr[curr]>arr[prev]){
        inc=1+solvedp(arr,curr+1,curr,dp);
    }
    int exc=0+solvedp(arr,curr+1,prev,dp);
    dp[curr][prev+1]=max(inc,exc);
    return dp[curr][prev+1];
}
int solvetab(vector<int>arr){
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=-1;j--){
            int inc=0;
            if(j==-1 || arr[i]>arr[j]){
                inc=1+dp[i+1][i];
            }
            int exc=0+dp[i+1][j+1];
            int ans=max(inc,exc);
            dp[i][j+1]=ans;
        }
    }
    return dp[0][0];
}
int solveso(vector<int>arr){
    int n=arr.size();
    
    vector<int>prev(n+1,0);
    for(int i=n-1;i>=0;i--){
        vector<int>curr(n+1,0);
        for(int j=i;j>=-1;j--){
            int inc=0;
            if(j==-1 || arr[i]>arr[j]){
                inc=1+prev[i+1];
            }
            int exc=0+prev[j+1];
            curr[i+1]=max(inc,exc);
        }
        prev[i]=curr[i];
    }
    return prev[0];
}
int spacetab2(vector<int>arr){
    int n=arr.size();
    vector<int>dp(n+1,1);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(dp[i],ans);
            }
        }
    }
}
int main(){
    int n;
    vector<int>arr(n);
    int ans=solve(arr,0,-1);
    return 0;
}