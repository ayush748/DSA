#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int cnt1=0;
        int cnt2=0;
        int i=0;
        while(i<n-1){
            if(s[i]==s[i+1]){
                cnt1++;
            }
            i++;
        }
        if(cnt1<=2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}