#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,56,7,8,9};
    int n=arr.size();
    stack<int>st;
    reverse(arr.begin(),arr.end());
    vector<int>ans;
    int i=0;
    while(i<n){
        int val=-1;
        while(!st.empty() && arr[i]>=st.top()){
            st.pop();
        }
        if(!st.empty()){
            ans.push_back(st.top());
        }else{
            ans.push_back(-1);
        }
        st.push(arr[i]);
        i++;
    }
    reverse(ans.begin(),ans.end());
    return 0;
}