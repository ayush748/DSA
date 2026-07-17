#include<iostream>
#include<vector>
using namespace std;
int solve(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 2;
        }
    }
    if(ans==m){
        return 1;
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    int l=1;
    int h=m;
    int mid=l+(h-l)/2;
    while(l<=h){
        int midN=solve(mid,n,m);
        if(midN==1){
            return mid;
        }else if(midN==0){
            l=mid+1;
        }else{
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return 0;
}