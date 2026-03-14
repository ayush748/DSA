#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j){
    if(i==0 && j==0){
        return 0;
    }
    if(i<0 || j<0){
        return 1;
    }
    int up=solve(i-1,j);
    int down=solve(i,j-1);
    return up+down;
}
int solvedp(int i,int j,vector<vector<int>>dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=solvedp(i-1,j,dp);
    int down=solvedp(i,j-1,dp);
    dp[i][j]=up+down;
    return dp[i][j];
}
int solvetab(int n,int m){
    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int up=0;
            int down=0;
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                down=dp[i][j-1];
            }
            dp[i][j]=up+down;
        }
    }
    return dp[n-1][m-1];
}
int solvememo(int n,int m){
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            int up=0;
            int down=0;
            if(i==0 && j==0){
                curr[j]=1;
                continue;
            }
            if(i>0){
                up=prev[j];
            }
            if(j>0){
                down=curr[j-1];
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
int main(){
    int n;
    int m;
    cin>>n>>m;

    return 0;
}