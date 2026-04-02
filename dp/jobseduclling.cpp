#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& a, vector<int>& b, vector<int>& c){
    int n=a.size();
    vector<pair<int,pair<int,int>>> arr(n);

    for(int i=0;i<n;i++){
        arr[i]={b[i],{a[i],c[i]}};
    }

    sort(arr.begin(),arr.end());

    vector<int> dp(n);
    dp[0]=arr[0].second.second;

    for(int i=1;i<n;i++){
        int prev=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j].first<=arr[i].second.first){
                prev=dp[j];
                break;
            }
        }
        dp[i]=max(prev+arr[i].second.second,dp[i-1]);
    }

    return dp[n-1];
}