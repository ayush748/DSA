#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>&arr,int curr,int prev){
    if(curr>=arr.size()){
        return 0;
    }
    int inc=0;
    if(prev=-1 || arr[curr]>arr[prev]){
        inc=1+solve(arr,curr+1,curr);
    }
    int exc=0+solve(arr,curr+1,prev);
    int ans=max(inc,exc);
    return ans;
}
int solvetab(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<int>dp(n,1);
    vector<int>prev(n,0);
    int maxl=1;
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(prev[i]>maxl){
                    maxl=dp[i];
                    len=i;
                }
            }
        }
    }
    vector<int>ans;
    while(len>=0){
        ans.push_back(arr[len]);
        len=prev[len];
    }
}
int main(){
    int n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return  0;
}