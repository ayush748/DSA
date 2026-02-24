#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int i){
    if(i>arr.size()){
        return 0;
    }
    int inc=arr[i]+solve(arr,i+2);
    int exc=0+solve(arr,i+1);
    int ans=max(inc,exc);
    return ans;
}
int solve2(vector<int>arr,int i,vector<int>&dp){
    if(i>=arr.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int inc=arr[i]+solve2(arr,i+2,dp);
    int exc=0+solve2(arr,i+1,dp);
    int ans=max(inc,exc);
    dp[i]=ans;
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
    for(int i=0;i<n;i++){
        int temp=0;
        if(i+2<n){
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
    vector<int>brr;
    vector<int>crr;
    for(int i=0;i<n;i++){
        if(i==0){
            brr.push_back(arr[i]);
        }else if(i==n-1){
            crr.push_back(arr[i]);
        }else{
            brr.push_back(arr[i]);
            crr.push_back(arr[i]);
        }
    }
    int ans=solve(arr,0);
    return 0;
}