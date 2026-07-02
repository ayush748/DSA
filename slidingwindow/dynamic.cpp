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
    int k;
    cin>>k;
    int r=0;
    int l=0;
    int sum=0;
    int len=0;
    while(r<n){
        sum=sum+arr[r];
        while(sum>k){
            sum=sum-arr[l];
            l++;
        }
        if(sum<=k){
            len=max(len,r-l+1);
        }
        r=r+1;
    }
    cout<<len;
    return 0;
}