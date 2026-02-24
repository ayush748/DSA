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
int solve2(vector<int>arr,int i,vector<int>dp){
    if(i>=arr.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int inc=arr[i]+solve2(arr,i+2,dp);
    int exc=0+solve2(arr,i+1,dp);
    dp[i]=max(inc,exc);
    return dp[i];
}
int solve3(vector<int>arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    int prev=arr[n-1];
    int curr=0;
    int next=0;
    for(int i=n-2;i>=0;i++){
        int temp=0;
        if(i+2<0){
            temp=next;
        }
        int inc=arr[i]+temp;
        int exc=0+prev;
        curr=max(inc,exc);
        next=prev;
        prev=curr;
    }
    return prev;
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