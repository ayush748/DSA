#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int solve(vector<int>arr,int cap){
    int days=1;
    int curr=0;
    for(int w:arr){
        if(curr+w>cap){
            days++;
            curr=w;
        }else{
            curr=curr+w;
        }
    }
    return days;
}
int main(){
    vector<int>arr={5,4,5,2,3,4,5,6};
    int d=5;
    int s=*max_element(arr.begin(),arr.end());
    int e=accumulate(arr.begin(),arr.end(),0);
    while(s<e){
        int mid=s+(e-s)/2;
        int w=solve(arr,mid);
        if(w<=d){
            e=mid;
        }else{
            s=mid+1;
        }
    }
    return 0;
}