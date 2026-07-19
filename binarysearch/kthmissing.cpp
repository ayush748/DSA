#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        int miss=arr[mid]-(mid+1);
        if(miss<k){
            s=miss+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    cout<<k+e+1;
    return 0;
}