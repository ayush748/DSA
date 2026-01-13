#include<iostream>
#include<vector>
using namespace std;
int solve(int n){
    int val1=n%2;
    int ans=0;
    if(n==2){
        ans=2;
    }else if(n==3){
        ans=3;
    }else if(val1 == 0){
        ans=0;
    }else{
        ans=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=solve(n);
        cout<<ans<<endl;
    }
    return 0;
}