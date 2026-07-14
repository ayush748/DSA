#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insertedsort(stack<int>&st ,int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return ;
    }
    int top=st.top();
    st.pop();
    insertedsort(st,x);
    st.push(top);
}
void sortstack(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int top=st.top();
    st.pop();
    sortstack(st);
    insertedsort(st,top);
}
int main(){
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    sortstack(st);
    return 0;
}