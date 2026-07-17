#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1, 2, 4, 6, 8, 10};
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int t;
    int ans;
    while(s<=e){
        if(arr[mid]==t){
            ans=mid;
            break;
        }else if(arr[mid]<t){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    
    return 0;
}