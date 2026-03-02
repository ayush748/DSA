#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long x;
    long long y;
    cin>>x>>y;
    if(y%x!=0){
        cout<<-1;
        return 0;
    }
    long long val=y/x;
    long long cnt=0;
    while(val%2==0){
        
        cnt++;
        val=val/2;
    }
    while(val%3==0){
        
        cnt++;
        val=val/3;
    }
    
    if(val!=1){
        cout<<-1;
    }else{
        cout<<cnt;
    }

    return 0;
}