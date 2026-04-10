#include<iostream>
#include<vector>
using namespace std;
void solve(string s,string t){
    int n=s.size();
    int m=s.size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=m;
    int j=n;
    string ans="";
    while(i>0 && j>0){
        if(s[i-1]==t[i-1]){
            ans.push_back(s[i-1]);
            i++;
            j--;
        }
        
    }
}
int main(){
    string s;
    string t;
    solve(s,t);
    return 0;
}