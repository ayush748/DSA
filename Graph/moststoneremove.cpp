#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> rnk;

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int x,int y){
    int px = find(x);
    int py = find(y);

    if(px == py){
        return;
    }

    if(rnk[px] < rnk[py]){
        parent[px] = py;
    }
    else if(rnk[py] < rnk[px]){
        parent[py] = px;
    }
    else{
        parent[py] = px;
        rnk[px]++;
    }
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }

    parent.resize(n);
    rnk.resize(n,0);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1]){
                Union(i,j);
            }
        }
    }

    int grp = 0;

    for(int i=0;i<n;i++){
        if(find(i) == i){
            grp++;
        }
    }
    cout << n - grp;

    return 0;
}