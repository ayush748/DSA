#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>arr(n);
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].push_back({v,wt});
        arr[v].push_back({u,wt});
    }
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >pq;
    pq.push({0,0});
    vector<bool>isMst(n,false);
    vector<int>parent(n,-1);
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        if(isMst[node]){
            continue;
        }
        isMst[node]=true;
        sum=sum+wt;
        for(auto nbr:arr[node]){
            int nn=nbr.first;
            int nw=nbr.second;
            if(!isMst[nn]){
                pq.push({nw,nn});
                parent[nn]=node;
            }
        }
    }
    return 0;
}