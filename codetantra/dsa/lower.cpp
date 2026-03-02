#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>arr,int n,int x){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=0;
    while(s<=e)
    {
        if(arr[mid]>=ans){
            ans=mid;
            s=mid-1;
        }else{
            e=mid+1;
        }
        mid=s+(e-s)/2;
    }
    
}
int search(vector<int>arr,int target){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[s]<=arr[mid]){
            if(arr[s]<=target && target<arr[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(arr[mid]<target && target<=arr[s]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    return -1;
}
int solve1(vector<int>arr,int t){
    int l=0;
    int r=arr.size();
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==t){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<=t && t<arr[mid])
        }
    }
}
int upper(vector<int>arr,int n,int x){
    int s=0;
    int e=arr.size();
    int mid=s+(e-s)/2;
    int ans=0;
    while(s<=e){
        if(arr[mid]>=x){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
}
int main(){
    int n;
    cin>>n;
    int x;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n,x);
    return 0;
}