#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(s[i]==s[j]){
        return solve(s,i+1,j-1);
    }
    int a=solve(s,i+1,j);
    int b=solve(s,i,j-1);
    return 1+min(a,b);
}
int main(){
    string s="leetcode";
    int n=s.size();
    int ans=solve(s,0,n-1);
    cout<<ans;
    return 0;
}