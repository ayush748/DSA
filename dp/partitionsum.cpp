#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&nums,int i,int cnt,int sum ,int req,int total){
    if(i==nums.size()){
        if(cnt==req){
            return abs(total-2*sum);
        }
        return INT_MAX;
    }
    int nottake=solve(nums,i+1,cnt,sum,req,total);
    int take=INT_MAX;
    if(cnt<req){
        take=solve(nums,i+1,cnt+1,sum+nums[i],req,total);
    }
    return min(take,nottake);
}
int main(){
    int total=0;
    vector<int>nums;
    int n=nums.size();
    for(int i=0;i<n;i++){
        total=total+nums[i];
    }
    
    return 0;
}