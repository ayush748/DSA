#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> solve(vector<vector<vector<int>>>& adj,int s,int v){
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);

    dist[s]=0;
    st.insert({0,s});

    while(!st.empty()){
        auto it=*st.begin();
        st.erase(st.begin());

        int dis=it.first;
        int node=it.second;

        for(auto nbr:adj[node]){
            int adjnode=nbr[0];
            int edjw=nbr[1];

            if(dis+edjw<dist[adjnode]){
                if(dist[adjnode]!=1e9){
                    st.erase({dist[adjnode],adjnode});
                }
                dist[adjnode]=dis+edjw;
                st.insert({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}

int main(){
    int v=3;
    int s=2;

    vector<vector<vector<int>>> adj(v);

    adj[0].push_back({1,1});
    adj[0].push_back({2,6});
    adj[1].push_back({2,3});
    adj[1].push_back({0,1});
    adj[2].push_back({1,3});
    adj[2].push_back({0,6});

    vector<int> dijkstra=solve(adj,s,v);

    for(int i=0;i<v;i++){
        cout<<dijkstra[i]<<" ";
    }
    cout<<endl;

    return 0;
}