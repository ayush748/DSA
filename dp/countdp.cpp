#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int ans=(n-1)*(solve(arr,n-1)+solve(arr,n-2));
    return ans;
}
int topdownAppraoch(vector<int>arr,int n,vector<int>dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=(n-1)*(topdownAppraoch(arr,n-1,dp)-topdownAppraoch(arr,n-2,dp));
    return dp[n];
}
int bottomupApproach(vector<int>arr,int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    vector<long long>dp(n+1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
int spaceopt(int n){
    int prev1=0;
    int prev2=1;
    for(int i=3;i<=n;i++){
        int f=prev1;
        int s=prev2;
        int sum=(f+s);
        int ans=(i-1)*sum;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,n);
    return 0;
}