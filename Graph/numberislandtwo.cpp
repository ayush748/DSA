#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<int> rnk;
int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}
bool Union(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py){
        return false;
    }
    if(rnk[px] < rnk[py]){
        parent[px] = py;
    }
    else if(rnk[px] > rnk[py]){
        parent[py] = px;
    }
    else{
        parent[py] = px;
        rnk[px]++;
    }

    return true;
}
vector<int> numIslands2(int m,int n,vector<vector<int>>& positions){
    parent.resize(m * n);
    rnk.resize(m * n,0);
    for(int i=0;i<m*n;i++){
        parent[i] = i;
    }
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<int> ans;
    int islands = 0;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    for(auto pos : positions){
        int r = pos[0];
        int c = pos[1];
        if(grid[r][c] == 1){
            ans.push_back(islands);
            continue;
        }
        grid[r][c] = 1;
        islands++;
        int node = r * n + c;
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                int adjNode = nr * n + nc;
                if(Union(node,adjNode)){
                    islands--;
                }
            }
        }
        ans.push_back(islands);
    }
    return ans;
}
int main(){
    int m,n,k;
    cin>>m>>n;
    cin>>k;
    vector<vector<int>> positions(k,vector<int>(2));
    for(int i=0;i<k;i++){
        cin>>positions[i][0]>>positions[i][1];
    }
    vector<int> ans = numIslands2(m,n,positions);
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}