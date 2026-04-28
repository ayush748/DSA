#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int curr,int prev){
    if(curr>=arr.size() ){
        return 0;
    }
    int inc=0;
    if(prev!=-1 || arr[curr]!=arr[prev]){
        inc=1+solve(arr,curr+1,curr);
    }
    int exc=0+solve(arr,curr+1,curr);
    return max(inc,exc);
}
int solvedp(vector<int>arr,int curr,int prev,vector<vector<int>>& dp){
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
    return dp[curr][prev];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ans=solvedp(arr,0,-1,dp);
    cout<<ans;
    return 0;
}