#include<iostream>
#include<vector>
#include<string>
using namespace std;
string solve(string s,string t,int i,int j){
    if(i==s.size()){
        return t.substr(j);
    }
    if(j==t.size()){
        return s.substr(i);
    }
    if(s[i]==t[j]){
        return s[i]+solve(s,t,i+1,j);
    }
    string a=s[i]+solve(s,t,i+1,j);
    string b=t[j]+solve(s,t,i,j+1);
    if(a.size()<b.size()){
        return a;
    }else{
        return b;
    } 
}
string solvedp(string s,string t,int i,int j,vector<vector<string>>dp){
    if(i==s.size()){
        return t.substr(j);
    }
    if(j==t.size()){
        return s.substr(j);
    }
    if(s[i]==t[j]){
        dp[i][j]=s[i]+solvedp(s,t,i+1,j,dp);
    }
    if(dp[i][j]!=""){
        return dp[i][j];
    }
    string a=s[i]+solvedp(s,t,i+1,j,dp);
    string b=t[j]+solvedp(s,t,i,j+1,dp);
    if(a.size()<b.size()){
        return a;
    }else{
        return b;
    }
}
string solvetab(string s,string t){
    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n;
    int j=m;
    string ans="";
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans=ans+s[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            ans=ans+s[i-1];
            i--;
        }else{
            ans=ans+t[j-1];
        }
    }
    reverse(ans.begin(),ans.end());
    
    
}
int main(){
    string s="abac";
    string t="cab";
    string s=solve(s,t,0,0);
    return 0;
}