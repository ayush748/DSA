#include<iostream>
#include<vector>
using namespace std;
int solve(int s,int k,int m){
    int ans=0;

    if(s<=k){
        int val1=m%k;
        int val2=s-val1;
        if(val2<0){
            ans=0;
        }else{
            ans=val2;
        }
    }else{
        int val1=m/k;
        int val2=m%k;
        int val3;
        if(val1%2 == 0){
            val3=s;
        }else{
            val3=k;
        }
        ans=val3-val2;
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
        int s,k,m;
        cin>>s>>k>>m;
        int ans=solve(s,k,m);
        cout<<ans<<endl;
    }
    return 0;
}