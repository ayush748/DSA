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
    int target;
    cin>>target;
    int s=0;
    int e=n-1;
    bool ans=false;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            ans=true;
            continue;
        }
        if(arr[s]==arr[mid] && arr[mid]==arr[e]){
            s++;
            e--;
            continue;
        }
        if(arr[s]<=arr[mid]){
            if(arr[s]<=target && target<=arr[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(arr[mid]<=target && target<=arr[e]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        mid=s+(e-s)/2;
    }
    return 0;
}