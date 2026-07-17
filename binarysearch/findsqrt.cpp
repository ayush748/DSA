#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s=1;
    int e=n;
    int mid=s+(e-s)/2;
    while(s<=e){
        int val=mid*mid;
        if(val<=n){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    cout<<e;
    return 0;
}