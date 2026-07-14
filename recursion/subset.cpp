#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>arr,vector<int>brr,vector<vector<int>>ans,int i){
    if(i==arr.size()){
        ans.push_back(brr);
        return ;
    }
    brr.push_back(arr[i]);
    solve(arr,brr,ans,i+1);
    arr.pop_back();
    solve(arr,brr,ans,i+1);
}
int main(){
    vector<int>nums={1,2,3,4,5,6};
    int n=nums.size();
    vector<int>brr;
    vector<vector<int>>ans;
    solve(nums,brr,ans,0);
    return 0;
}