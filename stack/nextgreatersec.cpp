#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,3};
    int n=arr.size();
    stack<int>st;
    int n=arr.size();
    int i=2*n-1;
    vector<int>ans(n);
    while(i>=0){
        int it=i%n;
        int curr=arr[it];
        while(!st.empty() && curr>=st.top()){
            st.pop();
        }
        if(i<n){
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
        }
        st.push(curr);
        i--;
    }
    return 0;
}