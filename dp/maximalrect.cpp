#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nsl(vector<int>&h){
    stack<int>st;
    int n=h.size();
    int p=-1;
    vector<int>l(n);
    for(int i=0;i<n;i++){
        if(st.empty()){
            l[i]=p;
        }else{
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
                if(st.empty()){
                    l[i]=p;
                }else{
                    l[i]=st.top();
                }
            }
        }
        st.push(i);
    }
    return l;

}
vector<int>nsr(vector<int>&h){
    stack<int>st;
    int n=h.size();
    int p=n;
    vector<int>r(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            r[i]=p;
        }else{
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(st.empty()){
                r[i]=p;
            }else{
                r[i]=st.top();
            }
        }
        st.push(i);
    }
    return r;
}
int maxhi(vector<int>&arr){
    int n=arr.size();
    vector<int>r=nsr(arr);
    vector<int>l=nsl(arr);
    vector<int>w(n);
    for(int i=0;i<n;i++){
        w[i]=r[i]-l[i]-1;
    }
    int max_area=0;
    for(int i=0;i<n;i++){
        w[i]=r[i]-l[i]-1;
    }
    int max_area=0;
    for(int i=0;i<n;i++){
        int a=w[i]*arr[i];
        if(max_area<a){
            max_area=a;
        }
    }
    return max_area;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m,0));
    if(mat.size()==0){
        return 0;
    }
    int n=mat.size();
    int m=mat[0].size();
    vector<int>h(m);
    for(int i=0;i<m;i++){
        h[i]=(mat[0][i]=='1')?1:0;
    }
    int maxA=maxhe(h);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='0'){
                h[j]=0;
            }else{
                h[j]=h[j]+1;
            }
        }
        maxA=max(maxA,maxhe(h));
    }

    cout<<maxA;

    return 0;
}