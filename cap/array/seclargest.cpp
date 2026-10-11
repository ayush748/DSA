#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<arr[n-1];
    return 0;
}