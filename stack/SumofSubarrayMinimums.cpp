#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nsl(vector<int>& arr){
    int n=arr.size();
    stack<int>st;
    vector<int>res(n);
    int i=0;
    while(i<n){
        if(st.empty()){
            res[i]=-1;
        }else{
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }else{
                res[i]=st.top();
            }
        }
        i++;
    }
    return res;
}
vector<int>nsr(vector<int>& arr){
    int n=arr.size();
    vector<int>res(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            res[i]=n;
        }else{
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=n;
            }else{
                res[i]=st.top();
            }
        }
    }
    return res;
}
int main(){
    vector<int>arr={3,1,2,4};
    int n=arr.size();
    vector<int>left=nsl(arr);
    vector<int>right=nsr(arr);
    long long sum=0;
    long long mod=1e9+7;
    for(int i=0;i<n;i++){
        long long l=i-left[i];
        long long r=right[i]-i;
        long long w=l*r;
        long long c=(arr[i]*w)%mod;
        sum=(sum+c)%mod;
    }
    cout<<sum;
    return 0;
}