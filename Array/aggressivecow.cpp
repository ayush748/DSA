#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>arr,int k,int mid){
    int cnt=0;
    int n=arr.size();
    int last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=mid){
            last=arr[i];
            cnt++;
            if(cnt>=k){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    sort(arr.begin(),arr.end());
    int s=0;
    int e=arr.back()-arr.front();
    int mid=s+(e-s)/2;
    int ans=0;
    while(s<=e){
        if(solve(arr,k,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return 0;
}