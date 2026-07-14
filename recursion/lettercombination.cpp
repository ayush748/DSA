#include<iostream>
#include<vector>
using namespace std;
vector<string>ans;
void solve(string mp[],string s,int i,string op){
    if(i>s.size()){
        if(op.size()>0){
            ans.push_back(op);
        }
        return ;
    }
    string temp=mp[s[i]-'0'];
    for(auto ch:temp){
        op.push_back(ch);
        solve(mp,s,i+1,op);
        op.pop_back();
    }
}
int main(){
    string d;
    string mp[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int i=0;
    string op;
    solve(mp,d,0,op);
    return 0;
}