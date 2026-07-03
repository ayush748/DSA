#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int k){
    int n=arr.size();
    int l=0;
    int r=0;
    int sum=0;
    int cnt=0;
    while(r<n){
        sum=sum+arr[r];
        while(sum>l){
            sum=sum-arr[r];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans=solve(arr,k);;
    cout<<ans;
    return 0;
}