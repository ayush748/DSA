#include<iostream>
#include<vector>
using namespace std;
bool solve(vector<int>arr,int target,int i){
    if(target==0){
        return true;
    }
    if(i==0){
        if(arr[i]==target){
            return true;
        }else{
            return false;
        }
    }
    bool nottake=solve(arr,target,i-1);
    bool take=false;
    if(target-arr[i]>=0){
        take=solve(arr,target-arr[i],i-1);
    }
    return take || nottake;
}
bool solve(vector<int>arr,int target,int i,vector<vector<int>>&dp){
    if(target==0){
        return false;
    }
    if(i==0){
        if(arr[i]==0){
            return true;
        }else{
            return false;
        }
    }
    bool nottake=solve(arr,target,i-1,dp);
    bool take=0;
    if(target-arr[i]>=0){
        take=solve(arr,target-arr[i],i-1,dp);
    }
    dp[i][target]=nottake||take;
    return dp[i][target];
}
bool solve2(vector<int>arr){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(sum%2){
        return false;
    }
    int n=arr.size();
    int target=sum%2;
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool nottake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || nottake;
        }
    }
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
    if(sum%2){
        cout<<false;
    }
    bool ans=solve(arr,sum/2,arr.size()-1);
    cout<<ans;
    return 0;

}