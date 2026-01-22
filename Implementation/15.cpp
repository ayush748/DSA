#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    while (k--)
    {
        int val=n%10;
        if(val>0){
            n--;
        }else{
            n/=10;
        }
    }
    cout<<n;
    return 0;
}