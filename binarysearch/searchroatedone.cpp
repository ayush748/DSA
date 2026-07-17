#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1, 2, 2, 2, 4, 5, 6};
    int s=0;
    int x=2;
    int e=arr.size();
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==x){
            ans=mid;
        }
        if(arr[s]<=arr[mid]){
            if(arr[s]<=x && x<=arr[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(arr[mid]<=x && x<=arr[e]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        mid=s+(e-s)/2;
    }
    return 0;
}