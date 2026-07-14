#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int n,string &s,vector<string>&ans){
    if(n==s.size()){
        ans.push_back(s);
        return;
    }
    s.push_back('1');
    solve(n,s,ans);
    s.pop_back();
    if(s.empty() && s.back()!='0'){
        s.push_back('0');
        solve(n,s,ans);
        s.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    vector<string>ans;
    solve(n,s,ans);
    return 0;
}