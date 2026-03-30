#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int i,int sum){
    if(i==0){
        if(arr[0]==sum && sum==0){
            return 2;
        }
        if(arr[0]==sum || sum==0){
            return 1;
        }
        return 0;
    }
    int nottake=solve(arr,i-1,sum);
    int take=0;
    if(arr[i]<=sum){
        take=solve(arr,i-1,sum-arr[i]);
    }
    return take+nottake;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int ans=solve(arr,n,target);
    return 0;
}