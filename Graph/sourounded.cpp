#include<iostream>
#include<vector>
using namespace std;

void dfs(int n,int m,vector<vector<int>>&vis,vector<vector<char>>&mat){
    vis[n][m]=1;
    int ns=mat.size();
    int ms=mat[0].size();

    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};

    for(int i=0;i<4;i++){
        int row=n+delrow[i];
        int col=m+delcol[i];

        if(row>=0 && row<ns && col>=0 && col<ms 
           && !vis[row][col] && mat[row][col]=='O'){
            dfs(row,col,vis,mat);
        }
    }
}

vector<vector<char>> solve(int n,int m,vector<vector<char>> mat){
    if(n==0 || m==0) return mat;

    vector<vector<int>>vis(n,vector<int>(m,0));
    
    // top and bottom row
    for(int i=0;i<m;i++){
        if(!vis[0][i] && mat[0][i]=='O'){
            dfs(0,i,vis,mat);
        }
        if(!vis[n-1][i] && mat[n-1][i]=='O'){
            dfs(n-1,i,vis,mat);
        }
    }

    // left and right column
    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0]=='O'){
            dfs(i,0,vis,mat);
        }
        if(!vis[i][m-1] && mat[i][m-1]=='O'){
            dfs(i,m-1,vis,mat);
        }
    }

    // flip enclosed regions
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j]=='O'){
                mat[i][j]='X';
            }
        }
    }

    return mat;
}

int main(){
    vector<vector<char>>arr={
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    int n=arr.size();
    int m=arr[0].size();

    vector<vector<char>>ans = solve(n,m,arr);

    for(auto &row:ans){
        for(auto &c:row) cout<<c<<" ";
        cout<<endl;
    }

    return 0;
}