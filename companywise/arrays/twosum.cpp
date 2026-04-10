#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>solve(vector<int>arr,int target){
    int n=arr.size();
    int i=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int val=arr[i];
        int val2=target-arr[i];
        if(mp.find(val2)!=mp.end()){
            return {mp[val2],i};
        }
        mp[val]=i;
    }
    return {-1,-1};
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==target){
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    return 0;
}