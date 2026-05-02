#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prec(string s,string t){
    int n=s.size();
    int m=t.size();
    if((n-m)!=1){
        return false;
    }
    int i=0;
    int j=0;
    while(i<n){
        if(j<m && s[i]==t[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    return j==m;
}
int solve(vector<string>&words,int curr,int prev){
    if(curr>=words.size()){
        return 0;
    }
    int inc=0;
    if(prev==-1 || prec(words[curr],words[prev])){
        inc=1+solve(words,curr+1,curr);
    }
    int exc=0+solve(words,curr+1,prev);
    int ans=max(inc,exc);
    return ans;
}
int solvedp(vector<string>&words,int curr,int prev,vector<vector<int>>&dp){
    if(curr>=words.size()){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    int inc=0;
    if(prev==-1 || prec(words[curr],words[prev])){
        inc =1+solvedp(words,curr+1,curr,dp);
    }
    int exc=0+solvedp(words,curr+1,prev,dp);
    dp[curr][prev+1]=max(inc,exc);
    return dp[curr][prev+1];

}
int solvetab(vector<string>&arr){
    int n=arr.size();
    vector<int>dp(n+1,1);
    int  maxl=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(prec(arr[i],arr[j])){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxl=max(maxl,dp[i]);
    }
    return maxl;

}
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr[i]=s;
    }
    sort(arr.begin(),arr.end());
    int ans=solve(arr,0,-1);
    cout<<ans;
    return 0;
}