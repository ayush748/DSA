#include<iostream>
#include<vector>
using namespace std;
const int m=1e9+7;
int solve(long long a,long long b){
    if(b==0){
        return 1;
    }
    long long h=solve(a,b/2);
    long long r=(h*h)%m;
    if(b%2==1){
        r=(r*a)%m;
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    long long ans=(long long)(solve(5,(n+1)/2)*solve(4,n/2));
    cout<<ans;
    return 0;
}