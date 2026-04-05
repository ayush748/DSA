#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s="A man, a plan, a canal: Panama";
    string ans;
    int n=s.size();
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch>='A' && ch<='Z'){
            char val=tolower(ch);
            ans.push_back(val);
        }else if(ch>='a' && ch<='z'){
            ans.push_back(ch);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    int i=0;
    int j=ans.size()-1;
    bool flag=true;
    while(i<=j){
        if(ans[i]!=ans[j]){
            flag=false;
            break;
        }
        i++;
        j--;
    }
    return 0;
}