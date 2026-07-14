#include<iostream>
#include<vector>
using namespace std;
bool solve(string s,int i){
    int n=s.size();
    if(i>=(n/2)){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return solve(s,i+1);
}
int main(){
    string s;
    cin>>s;
    bool ans=solve(s,0);
    return 0;
}