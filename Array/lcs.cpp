#include<iostream>
#include<vector>
using namespace std;
int solve(string s,string t,int i,int j){
    if(i>=s.size() || j>=t.size()){
        return 0;
    }
    if(s[i]==t[j]){
        return  1+solve(s,t,i+1,j+1);
    }
    int a=solve(s,t,i+1,j);
    int b=solve(s,t,i,j+1);
    return max(a,b);

}
int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
    if(i>=s.size() || j>=t.size()){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return 1+solve(s,t,i+1,j+1,dp);
    }
    int a=solve(s,t,i+1,j);
    int b=solve(s,t,i,j+1);
    return max(a,b);
}

int main(){
    string s;
    string t;

    return 0;
}