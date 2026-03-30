#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int sum,int i){
    if(i==0){
        if(arr[0]==0 && sum==0){
            return 2;
        }
        if(arr[0]==0 || arr[0]==sum){
            return 1;
        }
        return 0;
    }
    int nottake=solve(arr,sum,i-1);
    int take=0;
    if(arr[0]<=sum){
        take=solve(arr,sum-arr[i],i-1);
    }
    return take+nottake;
}
int solve(vector<int>&arr,int sum,int i,vector<vector<int>>&dp){
    if(i==0){
        if(sum==0 && arr[i]==0){
            return 2;
        }
        if(sum==0 || arr[i]==sum){
            return 1;
        }
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int nottake=solve(arr,sum,i-1,dp);
    int take=0;
    if(arr[i]<=sum){
        take=solve(arr,sum-arr[i],i-1,dp);
    }
    dp[i][sum]=take+nottake;
    return dp[i][sum];
}
int solvetab(vector<int>arr,int sum){
    int n=arr.size();
    vector<vector<int>>brr(n,vector<int>(sum+1,0));
    if(arr[0]==0){
        brr[0][0]=2;
    }
    else{
        brr[0][0]=1;
    }
    if(arr[0]!=0 && arr[0]<=sum){
        brr[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int nottake=brr[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=brr[i-1][j-arr[i]];
            }
            brr[i][j]=take+nottake;
        }
    }
    return brr[n-1][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int target;
    cin>>target;
    if(abs(target)>sum || (target+sum)%2!=0){
        cout<<0;
        return 0;
    }
    sum=sum+target;
    int ans=solve(arr,sum,n);
    return 0;
}