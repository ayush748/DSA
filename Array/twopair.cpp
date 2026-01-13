#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int functionApproach1(vector<int>nums,int target){
    int n=nums.size();
    vector<int>arr;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((nums[i]+nums[j])==target){
                arr.push_back(i);
                arr.push_back(j);
                break;
            }
        }
    }
}
int functionApproach2(vector<int>nums,int target)
{
    int n=nums.size();
    unordered_map<int,int>mp;
    mp[nums[0]]=0;
    vector<int>arr;
    for(int i=1;i<n;i++)
    {
        int val= target-nums[i];
        if(mp.find(val)!=mp.end()){
            arr.push_back(i);
            arr.push_back(mp[val]);
            break;
        }
        mp[nums[i]]=i;
    }
}

// when order
int functionApproach3(vector<int>nums,int target){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int i=0;
    int j=n-1;
    vector<int>arr;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==target){
            arr.push_back(i);
            arr.push_back(j);
            break;
        }else if(sum<target){
            i++;
        }else{
            j++;
        }
    }
}
int main(){
    return 0;
}