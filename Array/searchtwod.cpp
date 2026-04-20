#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>arr={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target=23;
    int r=arr.size();
    int c=arr[0].size();
    int n=r*c;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int ir=mid/c;
        int ic=mid%c;
        int curr=arr[ir][ic];
        if(curr==target){
            return true;
        }else if(curr<target){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return 0;
}