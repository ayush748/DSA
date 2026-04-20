#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string s,string t,int i,int j){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(s[i]==t[j]){
        return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
    }else{
        return solve(s,t,i-1,j);
    }
}
int solvedp(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return solvedp(s,t,i-1,j-1,dp);
    }
    
}
int main(){
    string s;
    string t;
    int n=s.size();
    int m=s.size()
    int ans=solve(s,t,n,m);
    return 0;
}