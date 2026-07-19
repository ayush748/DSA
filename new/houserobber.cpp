#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int i){
    if(i>=arr.size()){
        return 0;
    }
    int inc=arr[i]+solve(arr,i+2);
    int exc=0+solve(arr,i+1);
    int ans=max(inc,exc);
    return ans;
}
int solve(vector<int>arr,int i,vector<int>&dp){
    int n=arr.size();
    if(i>=arr.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int inc=arr[i]+solve(arr,i+2,dp);
    int exc=0+solve(arr,i+1,dp);
    int ans=max(inc,exc);
    dp[i]=n;
    return dp[i];

}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,0);
    return 0;
}