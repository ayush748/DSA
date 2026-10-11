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
    int l=0;
    int h=n-1;
    int ans=n;
    int x;
    cin>>x;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>=x){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return 0;
}