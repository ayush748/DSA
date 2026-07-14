#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    stack<int>st;
    int num=INT_MIN;
    bool flag=false;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<num){
            flag=true;
            break;
        }
        while(!st.empty() && st.top()<arr[i]){
            int n3=st.top();
            st.pop();
        }
    }
    return 0;
}