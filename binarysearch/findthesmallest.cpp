#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int solve(vector<int>&arr,int mid){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+ceil((double)(arr[i])/(double)(mid));
    }
    return sum;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int s=0;
    int e=*max_element(arr.begin(),arr.end());
    int mid=s+(e-s)/2;
    int limit;
    while(s<=e){
        if(solve(arr,mid)){
            e=mid-1;;
        }else{
            s=mid+1;
        }
    }
    cout<<s;
    return 0;
}