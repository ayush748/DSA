#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n=1212;
    string s=to_string(n);
    reverse(s.begin(),s.end());
    cout<<s;
    int ans=0;
    while(n>0){
        int rev=n%10;
        ans=ans*10+rev;
        n=n/10;
    }
    return 0;
}