#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int src,vector<vector<int>>&adj,vector<int>visited,stack<int>st){
    visited[src]=1;
    for(auto nbr:adj[src]){
        if(!visited[nbr]){
            dfs(nbr,adj,visited,st);
        }
    }
}
vector<int>toposort(int n,vector<vector<int>>&adj){
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

}
int main(){
    return 0;
}