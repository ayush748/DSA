#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool solve(vector<int>arr,int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool ans=solve(arr,k);
        if(ans){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}