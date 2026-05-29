#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        mp[u].push_back({v,wt});
    }
    vector<int>dist(n,1e9);
    set<pair<int,int>>st;
    int s;
    dist[s]=0;
    st.insert({0,s});

    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;
        int dis=it.first;
        st.erase(it);
        for(auto it:mp[node]){
            int adjNode=it[0];
            int edgeN=it[1];
            if(dis+edgN<dist[adjNode]){
                if(dist[adjNode]!=1e9){
                    st.erase(dist[adjNode]);
                }
                
            }
        }
    }
    return 0;
}