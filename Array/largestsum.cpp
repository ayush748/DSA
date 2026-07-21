#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==0){
            maxi=i+1;
        }else{
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
    }
    cout<<maxi;
    return 0;
}