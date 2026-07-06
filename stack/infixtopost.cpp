#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixtopostfix(string s){
    stack<char>st;
    string res;
    int n=s.size();

    for(int i=0;i<n;i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z')||(c>='0' && c<='9')){
            res=res+c;
        }else if(c=='('){
            st.push(c);
        }else if (c==')'){
            while (st.top()!='(') {
                res= res+st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && prec(s[i])<=prec(st.top())) {
                res=res+st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << res << endl;
}
int main(){
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixtopostfix(exp);
    return 0;
}