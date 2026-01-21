#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        cout<<i<<" ";
        i++;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}