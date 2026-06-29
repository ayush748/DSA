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
    vector<int>l2r(n,1);
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i-1]){
            l2r[i]=max(l2r[i],l2r[i-1]+1);
        }
    }
    vector<int>r2l(n,1);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            r2l[i]=max(r2l[i],r2l[i+1]+1);
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=res+max(l2r[i],r2l[i]);
    }
    
    return 0;
}