#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    cout<<ans;
    return 0;
}