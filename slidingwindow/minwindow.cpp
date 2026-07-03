#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
string solve(string s,string t){
    int n=s.length();
    map<char,int> mp;
    for(char ch:t){
        mp[ch]++;
    }
    int reqcnt=t.length();
    int l=0,r=0;
    int minstart=0;
    int minwin=INT_MAX;
    while(r<n){
        char ch=s[r];
        if(mp[ch]>0){
            reqcnt--;
        }
        mp[ch]--;
        while(reqcnt==0){
            if(minwin>(r-l+1)){
                minwin=r-l+1;
                minstart=l;
            }
            char chi=s[l];
            mp[chi]++;
            if(mp[chi]>0){
                reqcnt++;
            }
            l++;
        }
        r++;
    }
    return (minwin==INT_MAX) ? "" : s.substr(minstart,minwin);
}
int main(){
    string s,t;
    cin>>s>>t;
    string ans=solve(s,t);
    cout<<ans<<endl;
    return 0;
}