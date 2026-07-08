#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main(){
    vector<int>arr={1, 3, 2, 4};
    
    int n=arr.size();
    int i=n-1;
    stack<int>st;
    vector<int>ans;
    while(i>=0){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans.push_back(st.top());
        }else{
            ans.push_back(-1);
        }
        i--;
    }

    return 0;
}