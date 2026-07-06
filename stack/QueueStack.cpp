#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class queuestack{
    public:
    stack<int>st;
    void push(int x){
        stack<int>temp;
        while(!st.empty()){
            st.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!st.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    int pop(){
        int x=st.top();
        st.pop();
        return x;
    }
    int front(){
        return st.top();
    }
    bool isEmpty(){
        return st.empty();
    }

};
int main(){
    return 0;
}