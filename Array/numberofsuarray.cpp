#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    int xr=0;
    mp[xr]++;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        xr=xr^arr[i];
        int x=xr^k;
        cnt=cnt+mp[x];
        mp[xr]++;
    }
    cout<<cnt<<endl;
    return 0;
}