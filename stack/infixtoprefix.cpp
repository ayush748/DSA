#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int prec(char c){
    if(c=='^')
        return 3;
    if(c=='*' || c=='/')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    string result;

    for(int i=0;i<s.length();i++){
        char c=s[i];

        if(isalnum(c)){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else{
            while(!st.empty() &&
                 ((prec(c)<prec(st.top())) ||
                 (prec(c)==prec(st.top()) && c!='^'))){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    cout<<"Postfix expression: "<<result<<endl;
}

int main(){
    string exp="(p+q)*(m-n)";
    cout<<"Infix expression: "<<exp<<endl;
    infixToPostfix(exp);
    return 0;
}