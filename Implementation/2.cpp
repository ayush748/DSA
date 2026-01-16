#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int ch=9-(s[i]-'0');
        if(i==0 && ch==0){
            continue;
        }
        if(ch<(s[i]-'0')){
            char c=(char)(ch+'0');
            s[i]=c;
        }
    }
    cout<<s;
    return 0;
}