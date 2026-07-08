#include<iostream>
#include<vector>
#include<stack>
using namespace std;
string postfixToInfix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if(isalnum(c)){
            st.push(string(1,c));
        }else{
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}
int main(){
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}