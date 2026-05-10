#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>arr,int l,int r){
    
    if(r-l<=1){
        return 0;
    }
    int res=INT_MAX;
    for(int i=l+1;i<r;i++){
        int cost=solve(arr,l,i)+solve(arr,i,r)+(arr[r]-arr[l]);
        res=min(res,cost);

    }
    return res;
}
int main(){
    int len;
    cin>>len;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    arr.insert(arr.begin(),0);
    arr.push_back(len);
    cout<<solve(arr,0,arr.size()-1);
    return 0;
}