#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<2<<" ";
        int i=n;
        while(i>=3){
            cout<<i<<" ";
            i--;
        }
        cout<<1<<endl;
    }
    return 0;
}