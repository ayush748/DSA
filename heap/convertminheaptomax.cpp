#include<iostream>
#include<vector>
using namespace std;
void maxHeapify(vector<int>arr,int n,int i){
    int la=i;
    int l=2*i+1;
    int r=2*i+2;
    if(la<n && arr[l]>arr[la]){
        la=l;
    }
    if(r<n && arr[r]>arr[la]){
        la=r;
    }
    if(la!=i){
        swap(arr[i],arr[la]);
        maxHeapify(arr,n,la);
    }

}
void covertMin(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    covertMin(arr);
    return 0;
}