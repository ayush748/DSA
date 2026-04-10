#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>arr={10, 5, 2, 7, 1, -10};
    int k=15;
    int n=arr.size();
    unordered_map<int,int>mp;
    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==k){
            ans=max(ans,i+1);
        }
        if(mp.find(sum-k)!=mp.end()){
            int val1=i-mp[sum-k];
            ans=max(val1,ans);
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }
    cout<<ans;
    return 0;
}