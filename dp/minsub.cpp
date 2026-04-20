#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;
int solve(string s,int i){
    if(i==s.size()){
        return 0;
    }

    vector<int>freq(26,0);
    int maxval=0;
    int minpartition=INT_MAX;
    for(int j=i;j<s.size();j++){
        char ch=s[j];
        freq[ch-'a']++;
        maxval=max(maxval,freq[ch-'a']);
        int uniq=0;
        for(int k=0;k<26;k++){
            if(freq[k]>0){
                uniq++;
            }
        }
        int len=j-i+1;
        if(len==uniq*maxval){
            int part=1+solve(s,j+1);
            minpartition=min(minpartition,part);
           
        }
    }
    return minpartition;

}
int solvetab(string s){
    int n=s.size();
    vector<int>dp(n+1,0);
    for(int i=1;i<n;i++){
        vector<int>freq(26,0);
        int maxval=0;
        int minpartition=INT_MAX;
        for(int j=i+1;j<n;j++){
            char ch=s[j];
            freq[ch-'a']++;
            maxval=max(maxval,freq[ch-'a']);
            int uniq=0;
            for(int k=0;k<26;k++){
                if(freq[k]>0){
                    uniq++;
                }
            }
            int len=j-i+1;
            if(len==uniq*maxval){
                int part=1+dp[j-1];
                minpartition=min(minpartition,part);

            }
        }
        dp[i]=minpartition;
    }
    dp[n];

}
int main(){
    string s="fabccddg";

    int ans=solve(s,0);
    cout<<ans;
    return 0;
}