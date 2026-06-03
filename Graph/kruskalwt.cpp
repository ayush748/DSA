#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> parent;
vector<int> wt;

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
        return;
    }
    if(wt[xp] >= wt[yp]){
        parent[yp]=xp;
        wt[xp]+=wt[yp];
    }
    else{
        parent[xp]=yp;
        wt[yp]+=wt[xp];
    }
}

int kruskal(vector<vector<int>>& vec){
    int sum=0;

    for(auto temp:vec){
        int u=temp[0];
        int v=temp[1];
        int d=temp[2];

        if(find(u)!=find(v)){
            Union(u,v);
            sum+=d;
        }
    }

    return sum;
}

int main(){
    int v,e;
    cin>>v>>e;

    vector<vector<pair<int,int>>> adj(v);

    for(int i=0;i<e;i++){
        int u,to,d;
        cin>>u>>to>>d;

        adj[u].push_back({to,d});
        adj[to].push_back({u,d});
    }

    parent.resize(v);
    wt.resize(v,1);

    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    vector<vector<int>> vec;

    for(int i=0;i<v;i++){
        for(auto temp:adj[i]){
            int u=i;
            int to=temp.first;
            int d=temp.second;

            if(u<to){
                vec.push_back({u,to,d});
            }
        }
    }

    sort(vec.begin(),vec.end(),
    [](vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    });

    cout<<kruskal(vec);

    return 0;
}