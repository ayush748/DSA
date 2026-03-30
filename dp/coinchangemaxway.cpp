#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& arr,int sum,int i){
    if(sum==0){
        return 1;
    }
    if(i==0){
        if(arr[0]==sum){
            return 1;
        }
        return 0;
    }
    int nottake=solve(arr,sum,i-1);
    int take=0;
    if(arr[i]<=sum){
        take=solve(arr,sum-arr[i],i-1);
    }
    return take+nottake;
}

int solvememo(vector<int>& arr,int sum,int i,vector<vector<int>>& dp){
    if(sum==0){
        return 1;
    }
    if(i==0){
        if(arr[0]==sum){
            return 1;
        }
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int nottake=solvememo(arr,sum,i-1,dp);
    int take=0;
    if(arr[i]<=sum){
        take=solvememo(arr,sum-arr[i],i-1,dp);
    }
    return dp[i][sum]=take+nottake;
}

int solvetab(vector<int>& arr,int sum){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    if(arr[0]<=sum){
        dp[0][arr[0]]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take+nottake;
        }
    }
    return dp[n-1][sum];
}

int solvespace(vector<int>& arr,int sum){
    int n=arr.size();
    vector<int> prev(sum+1,0),curr(sum+1,0);

    prev[0]=1;
    if(arr[0]<=sum){
        prev[arr[0]]=1;
    }

    for(int i=1;i<n;i++){
        curr[0]=1;
        for(int j=1;j<=sum;j++){
            int nottake=prev[j];
            int take=0;
            if(arr[i]<=j){
                take=prev[j-arr[i]];
            }
            curr[j]=take+nottake;
        }
        prev=curr;
    }
    return prev[sum];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;

    int a=solve(arr,sum,n-1);

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    int b=solvememo(arr,sum,n-1,dp);

    int c=solvetab(arr,sum);

    int d=solvespace(arr,sum);

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
}