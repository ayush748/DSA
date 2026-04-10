// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,int> mp;
        
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]] = 1;
//         }
        
//         int ans = 0;
        
//         for(int i=0;i<n;i++){
//             int x = nums[i];
            
//             // start of sequence
//             if(mp.find(x-1) == mp.end()){
//                 int cnt = 1;
//                 int cur = x;
                
//                 while(mp.find(cur+1) != mp.end()){
//                     cur++;
//                     cnt++;
//                 }
                
//                 ans = max(ans, cnt);
//             }
//         }
        
//         return ans;
//     }
// };

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>nums={100,4,200,1,3,2};
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]=1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int x=nums[i];
        if(mp.find(x-1)==mp.end()){
            int cnt=1;
            int cur=x;
            while(mp.find(cur+1)!=mp.end()){
                cur++;
                cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    return 0;
}