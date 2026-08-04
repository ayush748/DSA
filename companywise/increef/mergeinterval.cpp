#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    int i=0;
    vector<vector<int>>ans;
    while(i<n){
        int s=arr[i][0];
        int e=arr[i][1];
        int j=i+1;
        while(j<n && arr[j][0]<=e){
            e=max(e,arr[j][1]);
            j++;
        }
        ans.push_back({s,e});
        i=j;
    }
    return 0;
}