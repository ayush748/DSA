#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n,h,l;
    cin>>n>>h>>l;
    int ans;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int counth=0;
    int countl=0;
    int countboth=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=h && arr[i]<=l){
            countboth++;
        }
        else if(arr[i]<=h){
            counth++;
        }
        else if(arr[i]<=l){
            countl++;
        }
    }
    ans=min(counth,countl);
    int val1 = abs(counth - countl);
    int val2 = min(val1, countboth);
    ans=ans+val2;
    countboth=countboth-val2;
    ans=ans+countboth/2;
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