#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int val=target-arr[i];
        if(mp.find(val)!=mp.end()){
            cout<<mp[val]<<" "<<i;
        }
        mp[arr[i]]=i;

    }
    return 0;
}