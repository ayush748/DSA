#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={1,3,4,2};
    stack<int>st;

    reverse(arr.begin(),arr.end());
    vector<int>ans;
    int i=0;
    int n=arr.size();


    while(i<n){
        int val=arr[i];
        int val2=0;
        while(!st.empty() && st.top()<=val){
            st.pop();
        }
        if(!st.empty()){
            val2=st.top();
            ans.push_back(val2);
        }else{
            ans.push_back(-1);
        }
        st.push(val);
        i++;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
