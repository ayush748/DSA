#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    cin>>i;
    if(n&(i<<i)!=0){
        cout<<1;
    }
    if((n>>1)&1){
        cout<<1; 
    }

    // set the ith bit
    cout<<  (n | (1<<i));

    // clear the it bit

    cout<< (n&(~(i<<i)));

    // toggle the ith bit
    cout<<(n^(1<<i));
    // remove the last set bit
    cout<<((n)&(n-1));
    if((n & (n-1))==0){
        cout<<1;
    }
    // count the set bits
    // inside loop n=n& n-1  cnt++
    return 0;
}