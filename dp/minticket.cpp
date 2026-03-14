#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(int n,vector<int>&days,vector<int>&cost,int index){
    if(index>=n){
        return 0;
    }
    
    int opt1=cost[0]+solve(n,days,cost,index+1);
    int i=index;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int opt2=cost[1]+solve(n,days,cost,i);
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int opt3=cost[2]+solve(n,days,cost,i);
    return min(opt1,min(opt2,opt3));
}
int solvedp(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int opt1=cost[0]+solvedp(n,days,cost,index+1,dp);
    int i=index;
    for(i=index;i<n && days[i]<days[index];i++);
    int opt2=cost[1]+solvedp(n,days,cost,index,dp);
    for(i=index;i<n && days[i]<days[index];i++);
    int opt3=cost[2]+solvedp(n,days,cost,index+1,dp);
    dp[index]=min(opt1,min(opt2,opt3));
    return dp[index];
}
int bottomup(vector<int>days,vector<int>count){
    int n=days.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
        int opt1=count[0]+days[k+1];
        int i=k;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int opt2=count[0]+days[i];
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int opt3=count[0]+days[i];
        dp[k]=min(opt1,min(opt2,opt3));

    }
    return dp[0];
}
int main(){
    return 0;
}