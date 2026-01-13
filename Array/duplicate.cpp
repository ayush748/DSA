#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr){
    int n=arr.size();
    vector<int>brr;
    vector<int>crr;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            brr.push_back(arr[i]);
        }else{
            crr.push_back(arr[i]);
        }
    }

    for(int i=0;i<crr.size();i++){
        brr.push_back(crr[i]);
    }
    return brr;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int n=solve(arr);
    return 0;
}