#include<iostream>
#include<vector>
using namespace std;
bool solve(vector<int>arr,int n,int i){
    if(i>=n){
        return false;
    }
    if(i==n-1){
        return true;
    }
    for(int j=1;j<=arr[i];j++){
        if(solve(arr,n,i+j)){
            return true;
        }
    }
    return false;
}
int solvedp(vector<int>arr,int n,int i,vector<int>&dp){
    if(i>=n){
        return false;
    }
    if(i==n-1){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=false;
    for(int j=1;j<=arr[i];j++){
        if(solvedp(arr,n-1,j+i,dp)){
            ans=true;
            break;
        }
    }
    dp[i]=ans;
    return dp[i];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,n,0);
    return 0;
}