#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string s,int i,int j){
    while(i<=j){
        if(s[i]=!s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    string s="aba";
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            int flag1=solve(s,i+1,j);
            int flag2=solve(s,i,j-1);
            if(flag1==false && flag2==false){
                return false;
            }
            return true;
        }
        i++;
        j--;
    }
    return 0;
}