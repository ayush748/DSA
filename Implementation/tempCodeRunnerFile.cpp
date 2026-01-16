#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int cnt=0;
    vector<int>arr;
    while(n>0){
        int val1=n%10;
        if(val1){
            int ans=pow(10,cnt);
            ans=ans*(n%10);
            arr.push_back(ans);
        }
        n=n/10;
        cnt++;
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}