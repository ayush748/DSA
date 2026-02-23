#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int n,string s) {
    int cntZero=0;
    int cntOne=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cntZero++;
        }
        else{
            cntOne++;
        }
    }
    if(cntOne%2 == 0){
        cout<<cntOne<<endl;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                cout<<i+1<<" ";
            }
            i++;
        }
    }
    else if(cntZero%2 != 0){
        cout<<cntZero<<endl;
        int i=0;
        while(i<n){
            if(s[i] == '0'){
                cout<<i + 1<<" ";
            }
            i++;
        }
    }
    else{
        cout<<-1;
    }
    cout<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
    }
    return 0;
}