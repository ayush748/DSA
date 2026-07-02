#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// int solve(string s,int k){
//     unordered_map<char,int>mp;
//     int n=s.size();
//     int l=0;
//     int r=0;
//     int maxlen=0;
//     int maxfreq=0;
//     while(r<n){
//         mp[s[r]]++;
//         maxfreq=max(maxfreq,mp[s[r]]);
//         while((r-l+1)-maxfreq>k){
//             mp[s[l]]--;
//             l++;
//         }
//         maxlen=max(maxlen,r-l+1);
//     }
//     return maxlen;
// }
int solve(string s,int k){
    int n=s.size();
    int r=0;
    int l=0;
    int maxfreq=0;
    int maxlen=0;
    unordered_map<char,int>mp;
    while(r<n){
        mp[s[r]]++;
        maxfreq=max(maxfreq,mp[s[r]]);
        while((r-l+1)-maxfreq>k){
            mp[s[l]]--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
    }
    return maxlen;
}
int solve2(string s,int k){
    int n=s.size();
    int l=0;
    int r=0;
    int maxlen=0;
    int maxfreq=0;
    unordered_map<char,int>mp;
    while(r<n){
        mp[s[r]]++;
        maxfreq=max(maxfreq,mp[s[r]]);
        if((r-l+1)-maxfreq>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        maxlen=max(maxlen,(r-l+1));
        r++;
    }
    return maxlen;
}
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int ans=solve(s,k);
    return 0;
}