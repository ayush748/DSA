#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int solve(vector<int>arr,int n){
    unordered_map<int,int>mp;
    int maxlen=0;
    int l=0;
    int r=0;
    while(r<n){
        mp[arr[r]]++;
        while(arr.size()>2){
            mp[arr[l]]--;
            if(mp[arr[l]]==0){
                mp.erase(arr[l]);
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int ans=solve(arr,n);
    return 0;
}