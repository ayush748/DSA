#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0;
    bool flag=false;
    while(s<n){
        if(arr[s]==67){
            flag=true;
            break;
        }
        s++;
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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