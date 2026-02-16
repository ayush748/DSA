#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(2*n); 
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=abs(arr[n]-arr[n-1]);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}