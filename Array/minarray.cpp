#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=INT_MAX;
    while(s<=e){
        if(arr[s]<=arr[mid]){
            ans=min(ans,arr[s]);
            s=mid+1;
        }else{
            ans=min(ans,arr[mid]);
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return 0;
}