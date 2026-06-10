#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<unordered_set>
using namespace std;
vector<int>parent;
vector<int>sz;
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(x);
}
void Union(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px==py){
        return ;
    }
    if(sz[px]>sz[py]){
        parent[py]=px;
        sz[px]=sz[px]+sz[py];
    }else{
        parent[py]=sz[px];
        sz[py]=sz[py]+sz[px];
    }
}
int getSize(int x){
    return sz[find(x)];
}
int largestIsland(vector<vector<int>>&grid){
    int n=grid.size();
    vector<vector<int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int total=n*n;
    parent.resize(total);
    sz.assign(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                unordered_set<int>st;
                int idx=i*n+j;
                for(auto &d:dir){
                    int ni=i+d[0];
                    int nj=j+d[1];
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[i][j]==1){
                        int nidx=ni*n+nj;
                        st.insert(find(nidx));
                    }
                }
                int area=1;
                for(auto p:st){
                    area=area+getSize(p);
                }
                
            }
        }
    }
}
int main(){

    return 0;
}