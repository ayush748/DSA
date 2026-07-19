#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int solve1(vector<int>&arr,int val){
    int s=0;
    long long p=0;
    for(int i=0;i<arr.size();i++){
        if(p+arr[i] <= p){
            p=p+arr[i];
        }else{
            s++;
            p=arr[i];
        }
    }
    return s;


}
int solve(vector<int>arr,int m){
    int n=arr.size();
    if(m>n){
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid=low+(high-low)/2;
        int student=solve1(arr,mid);
        if(student>m){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<solve(arr,m);
    return 0;
}