#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string s,string t,int i,int j){
    if(i>=s.size() || j>=t.size()){
        return 0;
    }
    if(s[i]==t[j]){
        return 1+solve(s,t,i+1,j+1);
    }
    int a=solve(s,t,i+1,j);
    int b=solve(s,t,i,j+1);
    return max(a,b);

}
int solvedp(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    if(i>=s.size() || j>=t.size()){
        return 0;
    }
    if(s[i]==t[j]){
        return 1+solvedp(s,t,i+1,j+1,dp);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=solvedp(s,t,i+1,j,dp);
    int b=solvedp(s,t,i,j+1,dp);
    return max(a,b);
}
int solve(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                dp[i][j]=max(a,b);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s="sea";
    string t="eat";
    int ans=solve(s,t,0,0);
    int val=s.size()+t.size()-2*ans;
    cout<<ans; 
    return 0;
}