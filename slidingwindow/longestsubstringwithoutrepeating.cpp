#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char>hash(256,-1);
    int l=0;
    int r=0;
    int maxlen=0;
    while(r<n){
        if(hash[s[r]]!=-1){
            l=max(hash[s[r]]+1,l);
        }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;
        r++;
    }
    cout<<maxlen;
    return 0;
}