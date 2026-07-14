#include<iostream>
#include<vector>
using namespace std;
vector<string>res;
bool isValid(string str) {
    int count = 0;

    for(char ch:str) {
        if(ch == '(')
            count++;
        else
            count--;
        if(count < 0)
            return false;
    }
    return count==0;
}
void solve(string &curr,int n){
    if(curr.length()==2*n){
        if(isValid(curr)){
            res.push_back(curr);
        }
        return ;
    }
    curr.push_back('(');
    solve(curr,n);
    curr.pop_back();
    curr.push_back(')');
    solve(curr,n);
    curr.pop_back();
}
int main(){
    string curr="";
    int n;
    solve(curr,n);

    return 0;
}