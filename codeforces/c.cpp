#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(int n){
    vector<pair<int,int>>arr(n + 1);
    arr[n].first=n;
    arr[n].second=1;
    for (int i=2;i<=n-1;i++){
        arr[i].first=i;
        arr[i].second=i^1;
    }
    arr[1].first=1;
    if (n%2==0){
        arr[1].second=n;
    }else{
        arr[1].second=n-1;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i].second;
        if (i<n){
            cout<<" ";
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
        cout<<endl;
    }
    return 0;
}
