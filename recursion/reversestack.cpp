#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insertatbottom(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return ;
    }
    int top=st.top();
    st.pop();
    insertatbottom(st,x);
    st.push(top);
}
void solve(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int top=st.top();
    st.pop();
    solve(st);
    insertatbottom(st,top);
}
int main(){
    stack<int>st;
    int n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    solve(st);
    return 0;
}