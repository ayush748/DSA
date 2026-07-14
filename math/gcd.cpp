#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int val=min(n,m);
    int ans=0;
    for(int i=val;i>=1;i--){
        if((n%i == 0) && (m%i == 0)){
            ans=i;
            break;
        }
    }
    int a,b;
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0){
        cout<<b;
    }else{
        cout<<a;
    }
    cout<<ans;
    return 0;  
}