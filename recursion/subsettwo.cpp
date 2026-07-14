#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>ans;
void solve(vector<int>&nums,vector<int>&arr,int i){
    ans.push_back(arr);
        
    for(int j=i;j<nums.size();j++){
        if(i!=j && nums[j-1]==nums[j]){
            continue;
        }
        arr.push_back(nums[j]);
        solve(nums,arr,j+1);
        arr.pop_back();
    }
    
}
int main(){
    vector<int>nums={1,2,3,4,56,7,7,7,7};
    vector<int>arr;
    sort(nums.begin(), nums.end());
    solve(nums,arr,0);
    return 0;
}