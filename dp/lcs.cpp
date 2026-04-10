#include<iostream>
#include<vector>
using namespace std;
int solve(string s,string t,int i,int j){
    if(i>s.size() || j>t.size()){
        return 0;
    }
    if(s[i]==t[j]){
        return 1+solve(s,t,i+1,j+1);
    }
    int a=solve(s,t,i+1,j);
    int b=solve(s,t,i,j+1);
    return max(a,b);
}
int solvememo(string s,string t,int i,int j,vector<vector<int>>dp){
    if(i>=s.size() && j>=t.size()){
        return 0;
    }
    if(s[i]==t[j]){
        dp[i][j]=1+solvememo(s,t,i+1,j+1,dp);
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=solvememo(s,t,i+1,j,dp);
    int b=solvememo(s,t,i,j+1,dp);
    dp[i][j]=max(a,b);
    return dp[i][j];

}
int solve(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                arr[i-1][j-1]=0;
            }else if(s[i-1]==t[i-1]){
                arr[i][j]=1+arr[i-1][j-1];
            }else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[m][n];
}
int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;

    int ans=solve(s,t,0,0);
    return 0;
}