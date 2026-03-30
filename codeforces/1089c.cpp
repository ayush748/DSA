#include<iostream>
#include<vector>
#include <numeric> 
#include <algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>brr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int i=0;
    int ans=0;
    if(n==1){
        cout<<0;
        return;
    }
    while(i<n){
        int val1=0;
        if(i==0){
            val1=gcd(arr[0],arr[1]);
        }else if(i==n-1){
            val1=gcd(arr[n-2],arr[n-1]);
        }else{
            val1=lcm(gcd(arr[i-1],arr[i]),gcd(arr[i],arr[i+1]));
        }
        if(val1<arr[i]){
            ans++;
        }
        i++;
    }
    cout<<ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        
        solve();
        cout<<endl;
    }
    return 0;
}