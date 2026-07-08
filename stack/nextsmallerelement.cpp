#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>arr={4, 8, 5, 2, 25};
    int n=arr.size();
    stack<int>st;
    vector<int>ans;
    int i=n-1;
    while(i>=0){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans.push_back(st.top());
        }else{
            ans.push_back(-1);
        }
        st.push(arr[i]);
        i--;
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}