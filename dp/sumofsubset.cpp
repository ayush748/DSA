#include<iostream>
#include<vector>
using namespace std;

bool solveRec(int i,int target,vector<int>& arr){
    if(target==0){
        return true;
    }
    if(i==0){
        return arr[0]==target;
    }

    bool nottake=solveRec(i-1,target,arr);
    bool take=false;
    if(arr[i]<=target){
        take=solveRec(i-1,target-arr[i],arr);
    }

    return nottake||take;
}

bool solveMemo(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target==0){
        return true;
    }
    if(i==0){
        return arr[0]==target;
    }

    if(dp[i][target]!=-1){
        return dp[i][target];
    }

    bool nottake=solveMemo(i-1,target,arr,dp);
    bool take=false;
    if(arr[i]<=target){
        take=solveMemo(i-1,target-arr[i],arr,dp);
    }

    dp[i][target]=nottake||take;
    return dp[i][target];
}

bool solveTab(vector<int>& arr,int target){
    int n=arr.size();
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    if(arr[0]<=target){
        dp[0][arr[0]]=true;
    }

    for(int i=1;i<n;i++){
        for(int k=1;k<=target;k++){
            bool nottake=dp[i-1][k];
            bool take=false;
            if(arr[i]<=k){
                take=dp[i-1][k-arr[i]];
            }
            dp[i][k]=take||nottake;
        }
    }

    return dp[n-1][target];
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    vector<vector<int>> dp(n,vector<int>(target+1,-1));

    cout<<solveRec(n-1,target,arr)<<endl;
    cout<<solveMemo(n-1,target,arr,dp)<<endl;
    cout<<solveTab(arr,target)<<endl;

    return 0;
}