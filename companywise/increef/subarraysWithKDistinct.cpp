#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int solve(vector<int>&nums,int k){
    int n=nums.size();
    int l=0;
    int r=0;
    int cnt=0;
    unordered_map<int,int>mp;
    while(r<n){
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int ans = solve(nums,k) - solve(nums,k-1);
    cout<<ans;
    return 0;
}