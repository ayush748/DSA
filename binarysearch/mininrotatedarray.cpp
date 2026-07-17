#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int s=0;
    int e=arr.size()-1;
    int ans=INT_MAX;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[s]<=arr[mid]){
            ans=min(ans,arr[s]);
            s=mid+1;
        }else{
            e=mid-1;
            ans=min(ans,arr[mid]);
        }
        mid=s+(e-s)/2;
    }
    return 0;
}