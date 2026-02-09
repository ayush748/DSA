#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int i=0;
    int n=s.size();
    int cnt=0;

    int f=-1;
    int l=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(f==-1){
                f=i;
            }
            l=i;
        }
    }
    for(int i=f;i<=l;i++){
        if(s[i]=='0'){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}