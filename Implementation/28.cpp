#include<iostream>
#include<string>
#include<vector>
#include <cctype>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i=0;
    int n=s.size();
    string ans;
    while(i<n){
        char ch=s[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            i++;
            continue;
        }else{
            char val1=tolower(ch);
            ans.push_back('.');
            ans.push_back(val1);
        }
        i++;
    }
    cout<<ans;
    return 0;
}