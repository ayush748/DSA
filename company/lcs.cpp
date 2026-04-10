#include<iostream>
#include<vector>
#include<string>
using namespace std;
int rec(string s,string t,int i,int j){
    if(i>=s.size() && j>=t.size()){
        return 0;

    }
    if(s[i]==t[j]){
        return 1+rec(s,t,i+1,j+1);
    }
    return max(rec(s,t,i+1,j),rec(s,t,i,j+1));
}
int recmemo(string s,string t,int i,int j,vector<vector<int>>dp){
    if(i>=s.size() && j>=t.size() ){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        dp[i][j]=1+recmemo(s,t,i+1,j+1,dp);

    }else{
        dp[i][j]=max(recmemo(s,t,i+1,j,dp),recmemo(s,t,i,j+1,dp));
    }
    return dp[i][j];
}
int main(){
    string s;
    string t;
    int n=s.size();
    int m=s.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans=rec(s,t,0,0);
    return 0;
}