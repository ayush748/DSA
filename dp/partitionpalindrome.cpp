#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    int cuts=INT_MAX;
    for(int k=i;k<=j;k++){
        int ans=1+solve(s,i,k)+solve(s,k+1,j);
        cuts=min(ans,cuts);
    }
    return cuts;
}
int main(){
    
    return 0;
}