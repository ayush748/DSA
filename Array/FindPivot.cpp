#include<iostream>
#include<vector>
using namespace std;
int functionPivot(vector<int>nums){
    int n=nums.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    int rightSum=0;
    int leftSum=0;
    int i=0;
    while(i<n){
        rightSum=totalSum-leftSum-nums[i];
        if(leftSum==rightSum){
            return i;
        }
        leftSum=leftSum+nums[i];
        i++;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val=functionPivot(arr);
    cout<<val;
    return 0;
}