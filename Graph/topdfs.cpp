#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;
void dfs(int src,unordered_map<int,vector<int>>&mp,stack<int>&st,vector<bool>&vis){
    vis[src]=true;
    for(auto nbr:mp[src]){
        if(!vis[nbr]){
            dfs(nbr,mp,st,vis);
        }
    }
    st.push(src);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                mp[i].push_back(j);
            }
        }
    }

    stack<int>st;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,mp,st,vis);
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    





    return 0;
}