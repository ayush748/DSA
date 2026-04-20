#include<iostream>
#include<vector>
using namespace std;
int function(int n){

    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    int ans=(function(n-1)+function(n-2))*(n-1);
    return ans;
}
int functionMemo(int n,vector<int>dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=(n-1)*(functionMemo(n-1,dp)+functionMemo(n-2,dp));

    return dp[n];

}

int main(){
    vector<int>arr;
    int n=arr.size();
    vector<int>dp(n+1,-1);

    return 0;
}