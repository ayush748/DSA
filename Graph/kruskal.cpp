#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int>parent;
vector<int>rnk;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp){
        return ;
    }
    if(rnk[xp]>rnk[yp]){
        parent[yp]=parent[xp];
    }else if(rnk[xp]<rnk[yp]){
        parent[xp]=parent[yp];
    }else{
        parent[xp]=parent[yp];
        rnk[yp]++;
    }
}
int kruskal(vector<vector<int>>&vec){
    int sum=0;
    for(auto temp:vec){
        int u=temp[0];
        int v=temp[1];
        int wt=temp[2];
        int parentu=find(u);
        int parentv=find(v);
        if(parentu!=parentv){
            Union(u,v);
            sum=sum+wt;
        }
    }
    return sum;
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    parent.resize(v);
    rnk.resize(v,0);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    vector<vector<int>>vec;
    for(int i=0;i<v;i++){
        for(auto temp:adj[i]){
            int u=i;
            int v=temp.first;
            int d=temp.second;
            vec.push_back({u,v,d});
        }
    }

    auto lambda=[&](auto &v1,auto &v2){
        return v1[2]<v2[2];
    };

    sort(vec.begin(),vec.end(),lambda);

    cout<<kruskal(vec);
    return 0;

}

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// #include<algorithm>
// using namespace std;
// int main(){
//     int v,e;
//     cin>>v>>e;
//     vector<vector<pair<int,int>>>adj;
//     for(int i=0;i<e;i++){
//         int u,v,wt;
//         cin>>u>>v>>wt;
//         adj[u].push_back({v,wt});
//     }
//     return 0;
// }