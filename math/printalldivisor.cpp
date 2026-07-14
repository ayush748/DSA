#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    // brute
    // for(int i=1;i<=n;i++){
    //     if(n%i==0){
    //         cout<<i<<" ";
    //     }
    // }
    // 
    for(int i=0;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if((n/i)!=i){
                cout<<(n/i);
            }
        }
    }
    return 0;  
}