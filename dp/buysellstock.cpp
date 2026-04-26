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
    int maxp=0;
    int mini=arr[0];

    for(int i=0;i<n;i++){
        int val=arr[i]-mini;
        maxp=max(val,maxp);
        mini=min(mini,arr[i]);
    }
    cout<<maxp;
    return 0;
}