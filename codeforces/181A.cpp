#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int n,string s){
    int i=0;
    bool flag=false;
    int val=0;
    while(i<n){
        if(s[i]!=s[(i+1)%n]){
            val++;
        }else{
            flag=true;
        }
        i++;
    }
    if(flag){
        cout<<val+1<<endl;
    }else{
        cout<<val<<endl;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
    }
    return 0;
}