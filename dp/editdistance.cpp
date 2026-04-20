#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string s,string t,int i,int j){
    if(i==s.size()){
        return t.size()-j;
    }
    if(j==t.size()){
        return s.size()-i;
    }
    int ans=0;
    if(s[i]==t[j]){
        ans= solve(s,t,i+1,j+1);
    }else{
        int insert=1+solve(s,t,i,j+1);
        int remove=1+solve(s,t,i+1,j);
        int replace=1+solve(s,t,i+1,j+1);
        ans=min(insert,min(replace,remove));
    }
    return ans;
}

int main(){
    string s="horse";
    string t="ros";
    int ans=solve(s,t,0,0);
    return 0;
}