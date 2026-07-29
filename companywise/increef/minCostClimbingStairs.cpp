#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int i){
    if(i==0){
        return arr[0];
    }
    if(i==1){
        return arr[1];
    }
    int inc=solve(arr,i-2);
    int exc=solve(arr,i-1);
    int ans=arr[i]+min(inc,exc);
    return ans;
}
int solvedp(vector<int>arr,int i,vector<int>dp){
    if(i==0){
        return arr[0];
    }
    if(i==1){
        return arr[1];
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int inc=solvedp(arr,i-1,dp);
    int exc=solvedp(arr,i-1,dp);
    int ans=min(inc,exc);
    return dp[i]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val1=solve(arr,n-1);
    int val2=solve(arr,n-2);
    int ans=min(val1,val2);
    cout<<ans;
    return 0;
}