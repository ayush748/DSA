#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;

    vector<int>hash(256,-1);
    int n=s.size();
    int l=0;
    int r=0;
    int maxlen=0;
    while(r<n){
        if(hash[s[r]]!=-1){
            l=max(l,hash[s[r]]+1);
        }
        maxlen=max(maxlen,r-l+1);
        hash[s[r]]=r;
        r++;
    }
    cout<<maxlen<<endl;
    return 0;
}