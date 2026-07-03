#include<iostream>
#include<vector>
using namespace std;
int solve(string s){
    int n=s.size();
    int l=0;
    int r=0;
    int cnt=0;
    vector<int>mp(3,0);
    while(r<n){
        char ch=s[r];
        mp[ch-'a']++;
        while(mp[0]>0 && mp[1]>0 && mp[2]>0){
            cnt=cnt+(n-r);
            mp[s[l]-'a']--; 
            l++;
        }
        r++;
    }
    return cnt;
}
int main(){
    string s;
    cin>>s;
    int ans=solve(s);
    return 0;
}