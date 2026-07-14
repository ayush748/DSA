#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> arr = {3, 1, 21, 4,-1 ,9,-10};
    stack<int>st;
    for(auto &a:arr){
        while(!st.empty() && a<0 && st.top()>0){
            int sum=a+st.top();
            if(sum<0){
                st.pop();
            }else if(sum>0){
                a=0;
                break;
            }else{
                a=0;
                st.pop();
            }
        }
        if(a!=0){
            st.push(a);
        }
    }
    int s = st.size();
    
    vector<int> result(s);
    int i = s-1;
    while(!st.empty()) {
        result[i] = st.top();
        st.pop();
        i--;
    }
    
    return 0;
}