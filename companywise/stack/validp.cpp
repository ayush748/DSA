#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    string s="()[]{}";
    int n=s.size();
    stack<int>st;
    int i=0;
    bool flag=true;
    while(i<n){
        char ch=s[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }else{
            if(st.empty()){
                flag=false;
            }else{
                if(ch==')' && st.top()=='('){
                    st.pop();
                }
                else if(ch==']' && st.top()==']'){
                    st.pop();
                }else if(ch=='{' && st.top()=='}'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
    }
    return 0;
}