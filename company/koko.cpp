#include<iostream>
#include<vector>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>arr,int speed){
    int totalh=0;
    for(auto it:arr){
        totalh+=(speed+it-1)/speed;
    }
    return totalh;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int h;
    cin>>h;
    
    int val=*max(arr.begin(),arr.end());
    int l=1;
    int h=val;
    int ans=val;
    int mid=l+(h-l)/2;
    int hr;
    cin>>hr;
    while(l<=h){
        int ans1=solve(arr,mid);
        if(ans1<=hr){
            ans1=hr;
            l=mid+1;
        }else{
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return 0;
}