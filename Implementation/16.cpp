#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k,w;
    cin>>k>>n>>w;
    int ans=k*(w*(w+1))/2;
    int val=ans-n;
    if(val<0){
        val=0;
    }
    cout<<val<<endl;
}