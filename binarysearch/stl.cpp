#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerbound(vector<int>arr,int x){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans;

    while(s<e){
        if(arr[mid]>=x){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;

}
int upperbound(vector<int>arr,int x){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans;
    while(s<e){
        if(arr[mid]>x){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int>arr={1, 2, 2, 2, 4, 5, 6};
    int x=2;
    cout<<lowerbound(arr,x);
    vector<int> v = {1, 2, 2, 2, 4, 5, 6};

    auto lb = lower_bound(v.begin(), v.end(), 2);
    auto ub = upper_bound(v.begin(), v.end(), 2);

    return 0;
}