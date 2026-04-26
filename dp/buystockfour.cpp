#include<iostream>
#include<vector>
using namespace std;
long solve(vector<int>arr,int i,int buy,int cap,int n){
    if(i==n || cap==0){
        return 0;
    }
    long profit=0;
    if(buy==0){
        profit=max(-arr[i]+solve(arr,i+1,1,cap,n),0+solve(arr,i+1,0,cap,n));
    }else{
        profit=max(arr[i]+solve(arr,i+1,0,cap-1,n),0+solve(arr,i+1,0,cap,n));
    }
    return profit;
}
int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,0,0,k,n);
    return 0;
}