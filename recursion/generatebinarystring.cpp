#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int n,string s,vector<string>& ans){
    if(n==s.size()){
        ans.push_back(s);
        return ;
    }
    solve(n,s+'0',ans);
    if(s.empty() || s.back()!=1){
        solve(n,s+'1',ans);
    }
    
}
int main(){
    int n=3;
    vector<string>ans;
    solve(n,"",ans);
    for(string s:ans){
        cout<<s;
    }
    return 0;
}