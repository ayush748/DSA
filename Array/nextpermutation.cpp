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
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(arr.begin(),arr.end());
        return 0;
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }
    reverse(arr.begin()+idx,arr.end());
    return 0;

}