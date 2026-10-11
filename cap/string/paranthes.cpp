#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char>st;
    string ans;
    int n=s.size();
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(st.size()==0 && ch==')'){
            st.push(ch);
        }else{
            if(ch=='('){
                ans.push_back(ch);
                st.push(ch);
            }else if(st.size()>1 && ch==')'){
                ans.push_back(ch);
                st.pop();
            }else{
                st.pop();
            }
        }
    }
    return 0;
}