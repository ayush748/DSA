#include<iostream>
using namespace std;
int main(){
    int dividend,divisor;
    cin>>dividend>>divisor;
    if(dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    long long n=abs((long long)dividend);
    long long d=abs((long long)divisor);
    long long ans=0;
    for(int i=31;i>=0;i--){
        if((d<<i)<=n){
            n=n-(d<<i);
            ans=ans-(1LL<<i);
        }
    }
    if((dividend<0)^(divisor<0)){

    }

}