#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve1(vector<int>arr,int x){
    int l=0;
    int h=arr.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){
            ans=mid;
            h=mid-1;
        }else if(arr[mid]<x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
int solve2(vector<int>arr,int x){
    int l=0;
    int h=arr.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==x){
            ans=mid;
            h=mid+1;
        }else if(arr[mid]<x){
            l=mid-1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={1,2,2,2,4,5,6};
    int x=2;
    cout<<solve1(arr,x);
    cout<<solve2(arr,x);
    return 0;
}