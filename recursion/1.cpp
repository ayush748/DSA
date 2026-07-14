#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cctype>
using namespace std;
int solve(string s,int i,int sign,long long num){
    if(i>=s.size() || !isdigit(s[i])){
        return sign*num;
    }
    int digit=s[i]-'0';
    if(sign==1){
        if(num>((INT_MAX-digit)/10)){
            return INT_MAX;
        }
    }else{
        if(num>(((long long)INT_MAX+1-digit))/10){
            return INT_MIN;
        }
    }
    return solve(s,i+1,sign,num*10+digit);
}
int myatoi(string s){
    int i=0;
    int n=s.size();
    while(i<n && s[i]==' '){
        i++;
    }
    int sign=1;
    if(i<n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        i++;
    }
    while(i<n && s[i]=='0'){
        i++;
    }
    if(i>=n || !isdigit(s[i])){
        return 0;
    }
    int ans=solve(s,i,sign,0);
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout<<myatoi(s);
    return 0;
}
