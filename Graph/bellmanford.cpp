#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n,e;
    vector<vector<int>>adj;
    for(int i=0;i<e;i++){
        int u;
        int v;
        int wt;
        cin>>u>>v>>wt;
        adj.push_back({u,v,wt});
    }
    int src;
    cin>>src;
    vector<int>ans(n,1e8);
    ans[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto nbr:adj){
            int u=nbr[0];
            int v=nbr[1];
            int wt=nbr[2];

            if(ans[u]!=1e8 && ans[u]+wt <ans[v]){
                ans[v]=ans[u]+wt;
            }
        }
    }
    bool flag=true;
    for(auto nbr:adj){
        int u=nbr[0];
        int v=nbr[1];
        int wt=nbr[2];
        if(ans[u]!=1e8 && ans[u]+wt<ans[v]){
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<-1;
    }
    return 0;
}