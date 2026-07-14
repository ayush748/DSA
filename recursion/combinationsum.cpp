#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>brr;
void solve(vector<int>& arr,vector<int>ans,int i,int t){
    if(t==0){
        brr.push_back(ans);
        return ;
    }
    if(i==arr.size() || t<0){
        return ;
    }
    if(arr[i]<=t){
        ans.push_back(arr[i]);
        solve(arr,ans,i,t-arr[i]);
        ans.pop_back();
    }
    solve(arr,ans,i+1,t);
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    vector<int>ans;
    int t=7;
    solve(arr,ans,t,0);
    return 0;
}