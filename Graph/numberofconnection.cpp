#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
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

    if(xp!=yp){
        return ;
    }

    if(rnk[xp]<rnk[yp]){
        parent[xp]=yp;
    }
    else if(rnk[xp]>rnk[yp]){
        parent[yp]=xp;
    }else{
        parent[yp]=xp;
        rnk[xp]++;
    }
}
int kruskal(int n,vector<vector<int>>vec){
    if(vec.size()-1<n){
        return -1;
    }
    int cnt=n;
    for(auto temp:vec){
        int u=temp[0];
        int v=temp[1];
        if(find(u)!=find(v)){
            Union(u,v);
            cnt--;
        }
    }
    return cnt-1;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>arr(e);
    for(int i=0;i<e;i++){
        for(int j=0;j<2;j++){
            int data;
            cin>>data;
            arr[i].push_back(data);
        }
    }
    rnk.resize(n,0);
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    cout<<kruskal(n,arr);

    return 0;
}