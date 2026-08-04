#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nsr(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>res(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            res[i]=n;
        }
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]=n;
        }else{
            res[i]=st.top();
        }
        st.push(i);
    }
}
vector<int>nsl(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>res(n);
    for(int i=0;i<n;i++){
        if(st.empty()){
            res[i]=-1;
        }
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]=-1;
        }else{
            res[i]=st.top();
        }
        st.push(i);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>prev=nsr(arr);
    vector<int>next=nsl(arr);
    vector<int>area(n);
    for(int i=0;i<n;i++){
        if()
    }
    return 0;
}