#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,-5,8,7,-9};
    int res=arr[0];
    int maxEnd=arr[0];
    int n=arr.size();

    for(int i=1;i<n;i++){
        maxEnd=max(arr[i],maxEnd+arr[i]);
        res=max(res,maxEnd);
    }
    cout<<res;
}