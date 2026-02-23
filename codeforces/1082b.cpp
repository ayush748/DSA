#include<iostream>
#include<string>
using namespace std;
void solve(int n,string s){
    if((n%2)==1 && s[0]=='b'){
        cout<<"No"<<endl;
        return; 
    }
    int i=0;
    if((n%2)==1){
        i=1;
    }
    while(i+1 < n){
        if(s[i] != '?'){
            if(s[i+1] != '?'){
                if(s[i] == s[i+1]){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        i=i+2;
    }
    cout<<"Yes"<<endl;
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