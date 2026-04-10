#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>arr={
        {1,2,-1},
        {4,-1,6},
        {7,8,9}};
    
    int n=arr.size();
    int m=arr[0].size();
    vector<int>brr;
    for(int i=0;i<n;i++){
        int ans=INT_MIN;
        for(int j=0;j<m;j++){
            ans=max(ans,arr[j][i]);
        }
        brr.push_back(ans);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==-1){
                arr[i][j]=brr[i];
            }
        }
    }

    return 0;
}