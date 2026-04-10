#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="A man, a plan, a canal: Panama";
    int n=s.size();
    string ans;
    int i=0;
    while(i<n){
        if(s[i]>='A' && s[i]<='Z'){
            char ch=tolower(s[i]);
            ans=ans+ch;
        }
        if(s[i]>='a' && s[i]<='z'){
            char ch=s[i];

            ans=ans+ch;
        }
        if(s[i]>='0' && s[i]<='9'){
            char ch=s[i];
            ans=ans+ch;

        }
        i++;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}