#include<iostream>
#include<vector>
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
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[s]<=arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return 0;
}