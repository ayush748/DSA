#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool solve(int i,int j,string s,string p){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(i>=0 && j<0){
        for(int k=0;k<=i;k++){
            if(s[i]!='*'){
                return false;
            }
        }
        return true;
    }
    if(s[i]==p[j] || s[i]=='?'){
        return solve(i-1,j-1,s,p);
    }
    if(s[i]=='*'){
        return solve(i-1,j,s,p) || solve(i,j-1,s,p);
    }
    return false;
}
bool solvedp(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    if(i<0 && j<0){
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(p[j]==s[i] || p[j]=='?'){
        dp[i][j]=solvedp(i-1,j-1,s,p,dp);
        return dp[i][j];
    }
    if(p[j]=='*'){
        dp[i][j]= solvedp(i-1,j,s,p,dp) || solvedp(i,j-1,s,p,dp);
        return dp[i][j];
    }
    dp[i][j]=false;
    return dp[i][j];
}
bool solvetab(string s,string p){
    int n=s.size();
    int m=p.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

    dp[0][0] = true;

    // pattern vs empty string
    for(int j=1;j<=m;j++){
        bool flag = true;
        for(int k=1;k<=j;k++){
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[j-1] == s[i-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s="aa";
    string p="a";
    int n=s.size();
    int m=p.size();
    bool ans=solve(n,m,s,p);

    return 0;
}